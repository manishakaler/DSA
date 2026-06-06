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
    bool isValidBST(TreeNode* root) {
        return valid(root, INT_MIN, INT_MAX);
    }

    bool valid(TreeNode* curr, int leftB, int rightB){
        if(curr == nullptr) return true;

        if(!(curr->val > leftB && curr->val < rightB)){
            return false;
        }

        return valid(curr->left, leftB, curr->val) && valid(curr->right, curr->val, rightB);
    }
};
