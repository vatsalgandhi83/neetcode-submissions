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
private:
    int result = 0;
    void helper(TreeNode* root, int currMax){
        if (root == NULL) {
            return;
        }

        if (root->val >= currMax) {
            result++;
            currMax = root->val;
        }

        helper(root->left, currMax);
        helper(root->right, currMax);
    }   
public:
    int goodNodes(TreeNode* root) {
        helper(root, INT_MIN);
        return result;
    }
};
