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

    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;

        int res = root->val;
        dfs(root, res);

        return res;
    }

private:
    int dfs(TreeNode* root, int& res){
        if( root == NULL) return 0;

        int leftMax = max(0, dfs(root->left, res));
        int rightMax = max(0, dfs(root->right, res));

        res = max(res, root->val + leftMax+ rightMax);

        return root->val + max(leftMax, rightMax);
    }
};

//TC - O(N)
//SC : O(N) auxillary space by recursion stack

