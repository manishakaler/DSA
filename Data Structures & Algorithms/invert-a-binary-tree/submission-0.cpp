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
    TreeNode* invertTree(TreeNode* root) {
        

        if(!root) return root;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left && curr->right){
                TreeNode* temp = curr->left;
                curr->left = curr->right;
                curr->right = temp;
                q.push(curr->left);
                q.push(curr->right);
            } else if(curr->left){
                curr->right = curr->left;
                curr->left = nullptr;
                q.push(curr->right);
            } else if(curr->right){
                curr->left = curr->right;
                curr->right = nullptr;
                q.push(curr->left);
            }

           
        }

        return root;
    }
};
