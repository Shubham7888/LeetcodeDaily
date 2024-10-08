/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode* solve(TreeNode* root,TreeNode* p,TreeNode* q){
    if(!root)
    return NULL;

    if(root==p || root==q){
        return root;
    }

    TreeNode* lefty=solve(root->left,p,q);
    TreeNode* righty=solve(root->right,p,q);

    if(lefty && righty){
        return root;
    }

    return lefty?lefty:righty;


  }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};