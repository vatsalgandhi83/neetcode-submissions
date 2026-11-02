class Solution {
private:
    char reverseParentheses(char c) {
        if (c == '(') return ')';
        if (c == ')') return '(';
        if (c == '{') return '}';
        if (c == '}') return '{';
        if (c == '[') return ']';
        if (c == ']') return '[';
        return 'x';
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else {
                if (st.size() && st.top() == reverseParentheses(c)) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return !st.size();
    }
};