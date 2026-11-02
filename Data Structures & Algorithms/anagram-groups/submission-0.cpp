class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        unordered_map<string, vector<string>> mp;
        for(auto str : strs) {
            string curr = str;
            sort(str.begin(), str.end());
            mp[str].push_back(curr);
        }

        for(auto i : mp) {
            res.push_back(i.second);
        }
        return res;
    }
};
