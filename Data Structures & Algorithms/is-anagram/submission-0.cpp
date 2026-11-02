class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        vector<int> sv(26, 0);
        vector<int> tv(26, 0);
        for(auto i : s) {
            sv[i - 'a']++;
        }
        for(auto i : t) {
            tv[i - 'a']++;
        }
        return sv == tv;
    }
};
