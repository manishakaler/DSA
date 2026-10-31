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
//diameter of a tree = height of the tree - you need to calculate height
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        //need to explore each subtree - dfs
        int diameter = 0;

        calculdateDepthofTree(root, diameter);

        return diameter;

    }

private:
    int calculdateDepthofTree(TreeNode* root, int& res){
        if(root == NULL) return 0;
        int left = calculdateDepthofTree(root->left,res);
        int right = calculdateDepthofTree(root->right,res);

        res = max(res, left + right);
        return 1 + max(left,right );
    }
};
