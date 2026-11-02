class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left <= right) {
            // while (nums[right] == val) {
            //     right--;
            // }
            if (nums[left] == val) {
                swap(nums[left], nums[right]);
                right--;
            } else {
                left++;
            }
            // left++;
        }
        return right + 1;
    }
};