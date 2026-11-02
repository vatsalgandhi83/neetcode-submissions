class Solution {
public:

    string encode(vector<string>& strs) {
        string result_string = "";
        for(string s : strs) {
            for (char c : s) {
                if (c == '.') {
                    result_string += "..";
                } else {
                    result_string += c;
                }
            }
            result_string += '.';
        }
        return result_string;
    }

    vector<string> decode(string s) {
        vector<string> result_vector;
        int n = s.size();
        string temp = "";
        for(int i = 0; i < n; i++) {
            if (s[i] == '.') {
                if (i + 1 < n && s[i + 1] == '.') {
                    temp += '.';
                    i++;
                } else {
                    result_vector.push_back(temp);
                    temp = "";
                }
            } else {
                temp += s[i];
            }
        }
        return result_vector;
    }
};
