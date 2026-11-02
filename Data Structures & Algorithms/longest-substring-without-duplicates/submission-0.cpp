class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> uset;
        int result = 0;
        int left = 0, right = 0;
        for(; right < n; right++) {
            while (uset.find(s[right]) != uset.end()) { // if found // O(1) operation
                result = max(result, (int) uset.size());
                uset.erase(s[left]);
                left++;
            }
            uset.insert(s[right]);
        } 
        result = max(result, (int) uset.size());
        return result;
    }
};
