class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> uset(nums.begin(), nums.end());
        int result = 0;

        for (auto i : uset) {
            if (uset.find(i - 1) != uset.end()) // 'i' cannot be a starting point element.
                continue;
            auto temp = i;
            int currLength = 1;
            while (uset.find(temp + 1) != uset.end()) {
                currLength++;
                temp++;
            }
            result = max(result, currLength);
        }
        return result;
    }
};