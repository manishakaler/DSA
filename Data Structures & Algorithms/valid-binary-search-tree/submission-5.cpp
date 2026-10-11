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
    bool checkForBSTHelper(TreeNode* curr, int maxLimit, int minLimit ){
        if(!curr) return true;

        if(curr->val <=minLimit || curr->val >= maxLimit) return false;

        return checkForBSTHelper(curr->left, curr->val, minLimit) && checkForBSTHelper(curr->right, maxLimit, curr->val); 
    }

    bool isValidBST(TreeNode* root) {
        return checkForBSTHelper(root, INT_MAX, INT_MIN);
    }
};
