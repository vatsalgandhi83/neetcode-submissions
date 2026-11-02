class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // vertical scanning
        string res = "";

        if(!strs.size()) {
            return res;
        }

        int i = 0;
        while(i < strs[0].size()){
            char curr = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                // cout << j << " " << strs[j][i] << endl;
                if (i >= strs[j].size() || strs[j][i] != curr) {
                    return res;
                }
            }
            res += curr;
            i++;
        }
        return res;
    }
};