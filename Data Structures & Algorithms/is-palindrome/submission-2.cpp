class Solution {
private:
    bool isAlphanumeric(char c) {
        return isalnum(c);
    }
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i < j) {
            if (!isAlphanumeric(s[i])) {
                i++;
            }
            else if (!isAlphanumeric(s[j])) {
                j--;
            }
            else if (tolower(s[i]) != tolower(s[j])) {
                return false;
            } else {
                i++;
                j--;
            }
        }
        return true;
    }
};