class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        s = unordered_set<int>(nums.begin(), nums.end());
        return s.size() < nums.size();
    }
};
