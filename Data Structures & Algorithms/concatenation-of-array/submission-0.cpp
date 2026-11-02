class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res = nums;
        for(auto i : nums) {
            res.push_back(i);
        }
        return res;
    }
};