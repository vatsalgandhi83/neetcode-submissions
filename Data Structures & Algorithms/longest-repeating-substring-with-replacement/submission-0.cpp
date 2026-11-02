class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, right = 0;
        int result = 0;
        vector<int> charCount(26, 0);
        int maxCount = 0;

        for(; right < n; right++) {
            charCount[s[right] - 'A']++;
            maxCount = max(maxCount, charCount[s[right] - 'A']);
            while ((right - left + 1) - maxCount > k) {
                charCount[s[left] - 'A']--;
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
