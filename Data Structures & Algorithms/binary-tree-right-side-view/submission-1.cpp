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

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};

        queue<TreeNode*>levelOrderTraversal;
        levelOrderTraversal.push(root);

        vector<int>rightSideV;
        vector<int>entriesCurrLevel;
        while(!levelOrderTraversal.empty()){
            int levelSize = levelOrderTraversal.size();

            for(int i = 0; i < levelSize; ++i){
                TreeNode* node = levelOrderTraversal.front();
                levelOrderTraversal.pop();
                entriesCurrLevel.push_back(node->val);
                if(node->left) levelOrderTraversal.push(node->left);
                if(node->right) levelOrderTraversal.push(node->right);
            }
            int lastEntryCurrLevel = entriesCurrLevel[entriesCurrLevel.size()-1];
            rightSideV.push_back(lastEntryCurrLevel);
            entriesCurrLevel.clear();
            vector<int>().swap(entriesCurrLevel);
            

        }

        return rightSideV;
    }

    //09 mins - stack has no erase or clear - vec clear() does not frees up memory allocation - only size goes to 0, not capacity 
    //for capacity to be zero - vec<int>().swap(your_vector); - when called after clear - SC and TC are O(1)


};
