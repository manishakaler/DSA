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
    void dfs(TreeNode* node, int maxInPath, int& count){
        if(node == nullptr){
            return;
        }

        if(node->val >= maxInPath){
            count++;
            maxInPath = max(maxInPath, node->val);
        }

        dfs(node->left, maxInPath, count);
        dfs(node->right, maxInPath, count);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        int maxInPath = root->val;

        dfs(root, maxInPath, count);

        return count;
    }
};

