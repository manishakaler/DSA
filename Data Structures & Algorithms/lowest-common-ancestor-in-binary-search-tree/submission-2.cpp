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
    void lookupHelper(TreeNode* curr, TreeNode* p, TreeNode* q, TreeNode* &lca){
        
        if((curr->val > p->val && curr->val < q->val) || (curr->val < p->val && curr->val > q->val)){
            lca = curr;
            return;
        }
        if(curr->val == p->val || curr-> val == q->val){
            lca=curr;
            return;
        }
        if(p->val < curr->val && q->val < curr->val){
            lookupHelper(curr->left, p,q,lca);
        }else{
            lookupHelper(curr->right, p,q,lca);
        }
           //cases covered so far - curr is in middle of p,q. curr is smaller than p and q. curr is greater than p and q.
           //case rem - curr is equal to either p or q
          
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca ;
    
        //if(!root->left || !root->right) return root;

        if(p->val == root->val || q->val == root->val){
            return root;
        }
        lookupHelper(root, p, q, lca);

        return lca;
        
            
       
    }
};
