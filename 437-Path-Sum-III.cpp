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
  long long int solve(TreeNode* root,int &t,long long int sum){
      if(!root)
      return 0;

     long long int ans=0;

      if(sum+root->val==t)
        ans++;

    long long int lefty=solve(root->left,t,sum+root->val);
    long long int righty=solve(root->right,t,sum+root->val);

      return lefty+righty+ans;
   }
    int pathSum(TreeNode* root, int t) {
       
        if(!root)
        return 0;

        long long int count=0;

      count+=solve(root,t,0);

       long long int lefty=pathSum(root->left,t);
       long long int righty=pathSum(root->right,t);

        return lefty+righty+count;
    }
};