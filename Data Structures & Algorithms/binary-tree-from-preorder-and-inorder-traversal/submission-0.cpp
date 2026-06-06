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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int np = preorder.size(), ni = inorder.size();

        if(np == 0 || ni == 0) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        unordered_map<int,int> inorderIndexMap;

        for(int i = 0; i < ni; i++){
            inorderIndexMap[inorder[i]] = i;
        }
        int mid = inorderIndexMap[root->val];
        vector<int>leftPre(preorder.begin()+1, preorder.begin()+ mid + 1);
        vector<int>rightPre(preorder.begin() + mid + 1, preorder.end());

        vector<int>leftIn(inorder.begin(), inorder.begin() + mid);
        vector<int>rightIn(inorder.begin()+ mid + 1, inorder.end());

        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);

        return root;
    }

};
