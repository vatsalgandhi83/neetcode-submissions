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
            while (i < j && !isAlphanumeric(s[i])) {
                i++;
            }
            while (i < j && !isAlphanumeric(s[j])) {
                j--;
            }
            if(tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
