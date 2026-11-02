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
    int diameter = 0;
    int calcMaxDiameter(TreeNode* root) {
        
        if(!root) return 0;

        int maxLeftDepth = calcMaxDiameter(root->left);
        int maxRightDepth = calcMaxDiameter(root->right); 

        this->diameter = max(this->diameter, maxLeftDepth + maxRightDepth);
        
        return 1 + max(maxLeftDepth, maxRightDepth);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDepth = calcMaxDiameter(root);
        return this->diameter;
    }
};