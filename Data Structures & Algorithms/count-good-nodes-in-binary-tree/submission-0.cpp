/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        stack<pair<TreeNode*, int>> stackPair;
        stackPair.push({root, root->val}); // current maximum

        int result = 0;

        while (!stackPair.empty()) {
            pair<TreeNode*, int> currPair = stackPair.top();
            stackPair.pop();
            int pastMax = currPair.second;
            if(currPair.first->val >= pastMax) {
                pastMax = currPair.first->val;
                result++;
            }

            if (currPair.first->left) stackPair.push({currPair.first->left, pastMax});
            if (currPair.first->right) stackPair.push({currPair.first->right, pastMax});
        }
        return result;
    }
};