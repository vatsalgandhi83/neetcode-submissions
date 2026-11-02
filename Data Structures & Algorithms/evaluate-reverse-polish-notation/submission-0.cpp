class Solution {
private:
    int operate(int& first, int& second, string& op) {
        if (op == "+") {
            return first + second;
        } else if (op == "-") {
            return first - second;
        } else if (op == "*") {
            return first * second;
        } else {
            return first / second;
        }
    }
    bool isOperator(string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
public:
    int evalRPN(vector<string>& tokens) { // postfix

        stack<int> st;
        for(auto token : tokens) {
            if (!isOperator(token)) {
                st.push(stoi(token));
            } else {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(operate(first, second, token));
            }
        }
        return st.top();
    }
};