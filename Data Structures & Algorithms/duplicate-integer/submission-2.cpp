class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto i : nums) {
            s.insert(i);
        }
        return s.size() != nums.size();
    }
};