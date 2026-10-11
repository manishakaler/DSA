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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //level order - BST - queue
    
        vector<vector<int>>response;
        vector<int>valArr;
        if(!root) return response;

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
           int levelSize = nodeQueue.size();
            valArr.clear();
           for(int i = 0; i <levelSize; ++i){
                TreeNode* curr = nodeQueue.front();
                valArr.push_back(curr->val);
                nodeQueue.pop();

                if(curr->left)nodeQueue.push(curr->left);
                if(curr->right)nodeQueue.push(curr->right);
           }
           response.push_back(valArr);

        }
        return response;
    }
};
