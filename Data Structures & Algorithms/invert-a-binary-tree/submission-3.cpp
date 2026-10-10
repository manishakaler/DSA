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
    void invertNodesHelper(TreeNode* curr){
        if(!curr) return;
        if(!curr->left && !curr->right) return;

        invertNodesHelper(curr->left);
        invertNodesHelper(curr->right);
        TreeNode* temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;

    }


    TreeNode* invertTree(TreeNode* root) {
        TreeNode* res;
        if(!root) return res;
        if(!root->right && !root->left) return root;

        invertNodesHelper(root);

        return root;
    }
};
