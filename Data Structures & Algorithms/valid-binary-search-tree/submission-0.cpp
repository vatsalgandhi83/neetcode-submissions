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
    bool isValidBSTHelper(TreeNode* root, long minPossible, long maxPossible) {
        if (!root) return true;

        // cout << maxPossible << " " << minPossible << endl;
        if (root->val >= maxPossible || root->val <= minPossible)
            return false;
        
        bool left = isValidBSTHelper(root->left, minPossible, root->val);
        bool right = isValidBSTHelper(root->right, root->val, maxPossible);
        // cout << root->val << " left right :" << left << " " << right << endl;
        return left && right;

    }
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }
};