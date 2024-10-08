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

  int ans=0;
 void solve(TreeNode* root,int dir,int count){
    if(!root){
    ans=max(ans,count);
    return ;
    }

    if(dir==0){
        solve(root->left,1,count+1);
       solve(root->right,0,1);
    }else{
        solve(root->right,0,count+1);
        solve(root->left,1,1);
    }
    
    

 }
    int longestZigZag(TreeNode* root) {
        solve(root,0,0);
        solve(root,1,0);

        return ans-1;
    }
};