class Solution {
public:
    string minWindow(string s, string t) {
        int ns = s.size();
        int nt = t.size();
        if (nt > ns) return "";

        unordered_map<char, int> count;

        for(char c : t) {
            count[c]++;
        }

        int minLength = INT_MAX; 
        int currentCount = 0; // no of char in 't' which are part of current window.
        int startIndex = -1;
        int left = 0, right = 0;

        for(; right < ns; right++) {
            if (count[s[right]] > 0) {
                currentCount++;
            }
            count[s[right]]--;
            while (currentCount == nt) {
                if(right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    startIndex = left;
                } 
                count[s[left]]++;
                if(count[s[left]] > 0) {
                    currentCount--;
                }
                left++;
            }
        }
        return (startIndex == -1) ? "" : s.substr(startIndex, minLength);
    }
};
