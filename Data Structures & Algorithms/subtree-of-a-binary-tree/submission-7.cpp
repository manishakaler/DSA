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
    bool isSameTree(TreeNode* nodeA, TreeNode* nodeB){
        if(!nodeA && !nodeB) return true;

        if((!nodeA || !nodeB) || (nodeA->val != nodeB->val)) return false;

        return isSameTree(nodeA->left, nodeB->left) && isSameTree(nodeA->right, nodeB->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //recursion
        //find same value node in the root tree as subroot and then check if they are the same tree
        if(!root) return false;
        if(!subRoot) return true;

        if(isSameTree(root,subRoot)) return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right,subRoot);

    }
};
