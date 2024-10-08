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
  int solve(TreeNode* root){
    if(!root)
    return 0;
    
    int lefty=solve(root->left);
    int righty=solve(root->right);

    return 1+max(lefty,righty);

  }
    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};