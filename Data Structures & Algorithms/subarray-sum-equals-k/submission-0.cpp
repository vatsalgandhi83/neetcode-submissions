class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int prefix_sum = 0;
        unordered_map<int, int> mp;
        mp[0]++;
        for(int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];
            res += mp[prefix_sum - k];
            mp[prefix_sum]++;
        }
        return res;
    }
};