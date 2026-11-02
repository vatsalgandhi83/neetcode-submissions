class Solution {
public:
    // int findDuplicate(vector<int>& nums) {
    //     int sum = 0;
    //     for(int i = 0; i<nums.size(); i++)
    //         sum += nums[i] - i;
    //     return sum;
    // }


    // ** CYCLE SORT **    
    // int findDuplicate(vector<int>& nums) {
        
    //     int i = 0, ans = 0;
    //     while(i < nums.size())
    //     {

    //         int index = nums[i] - 1;
    //         // cout << index << endl;
    //         if(nums[i] !=  nums[index])
    //         {
    //             int temp = nums[i];
    //             nums[i] = nums[index];
    //             nums[index] = temp;
    //         }
    //         else
    //             i++;
    //     }   
    //     for(auto j : nums)
    //         printf("%d ",j);
    //     printf("\n");
    //     return nums.back();
    // }


    // ** FLOYD's CYCLE ** (Without modifying the array)

    // Assume it as a linked list
    // For Example: 1 3 4 2 2
    // 0 -> 1 -> 3 -> 2 -> 4 -> 2 -> .... (cycle)

    // For Example: 3 1 3 4 2
    // 0 -> 3 -> 4 -> 2 -> 3 -> 4 -> ... (cycle)

    // same as 142 

    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detect the intersection point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find the entrance to the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow; // or fast, they are equal
    }
};