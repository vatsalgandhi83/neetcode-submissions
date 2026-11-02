class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            if (!count) {
                res = nums[i];
            }
            if (res == nums[i]) 
                count++;
            else
                count--;
        }

        return res;

    }
};