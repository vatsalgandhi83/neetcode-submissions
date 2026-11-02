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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size()) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);

        stack<TreeNode*> st;
        st.push(root);

        int inorderIterator = 0;

        for(int i = 1; i < preorder.size(); i++) {

            TreeNode* parent = st.top();
            TreeNode* curr = new TreeNode(preorder[i]);
            
            if (parent->val != inorder[inorderIterator]) {
                parent->left = curr;
            } else {
                while (!st.empty() && st.top()->val == inorder[inorderIterator]) {
                    parent = st.top(); // go reverse up
                    st.pop();
                    inorderIterator++;
                }
                parent->right = curr;
            } 

            st.push(curr);

        }

        return root;

    }
};