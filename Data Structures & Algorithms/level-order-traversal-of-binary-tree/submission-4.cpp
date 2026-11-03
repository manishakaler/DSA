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
    void dfs(TreeNode* node, int depth, vector<vector<int>>& entriesByLevel){
        if(node == nullptr) return;

        if(entriesByLevel.size() == depth){
            entriesByLevel.push_back(vector<int>());
        }

        entriesByLevel[depth].push_back(node->val);

        dfs(node->left, depth+1, entriesByLevel);
        dfs(node->right, depth+1, entriesByLevel);

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> entriesByLevel;
        int depth = 0;
        dfs(root, depth, entriesByLevel);

        return entriesByLevel;
    }

    //TC: O(n), SC: O(n)
};
