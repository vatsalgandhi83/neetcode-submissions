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
    pair<int, int> helper(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }
        // pair<int, int> => {if not taking the current root, if taking the current root}
        pair<int, int> left = helper(root->left); 
        pair<int, int> right = helper(root->right);

        int take = left.first + right.first + root->val;
        int notTake = max(left.first, left.second) + max(right.first, right.second); // this part is nice

        return {notTake, take};
    }
public:
    int rob(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }    

        pair<int, int> res = helper(root);

        return max(res.first, res.second);
    }
};