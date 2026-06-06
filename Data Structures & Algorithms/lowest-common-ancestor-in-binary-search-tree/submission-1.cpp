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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* currNode = root;

        while(currNode){
            if(p->val > currNode->val && q->val > currNode->val){
                currNode = currNode->right;
            }else if (p->val < currNode->val && q->val < currNode->val){
                currNode = currNode->left;
            }else {
                return currNode;
            }
        }

        return nullptr;
    }
};
 