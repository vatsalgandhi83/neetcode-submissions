class Solution {
    void generate(int openParenthesisLeft, int closeParenthesisLeft, string current, vector<string>& result) {
        if (!openParenthesisLeft && !closeParenthesisLeft) {
            result.push_back(current);
            return;
        }

        if (openParenthesisLeft > 0) {
            generate(openParenthesisLeft - 1, closeParenthesisLeft, current + "(", result);
        }

        if (openParenthesisLeft < closeParenthesisLeft) {
            generate(openParenthesisLeft, closeParenthesisLeft - 1, current + ")", result);
        }

        // if (openParenthesisLeft == closeParenthesisLeft) {
        //     generate(openParenthesisLeft - 1, closeParenthesisLeft, current + "(", result);
        // }

        // if (openParenthesisLeft < closeParenthesisLeft) {
        //     if (openParenthesisLeft > 0) {
        //         generate(openParenthesisLeft - 1, closeParenthesisLeft, current + "(", result);
        //     }
        //     generate(openParenthesisLeft, closeParenthesisLeft - 1, current + ")", result);
        // }

    }
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        generate(n-1, n, "(", result);
        return result;
    }
}; 