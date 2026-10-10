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
    int calcDepthHelper(TreeNode* curr, int& diameter){
        if (!curr) return 0;

        int leftDepth = calcDepthHelper(curr->left, diameter);
        int rightDepth = calcDepthHelper(curr->right, diameter);

        diameter = max(diameter, leftDepth+rightDepth);

        return 1+max(leftDepth, rightDepth);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        
        int treeDepth = calcDepthHelper(root, diameter);

        return diameter;
    }
};
