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
  void solve(TreeNode* root,vector<int>&a){
    if(!root)
    return;
  
  if(!root->left && !root->right){
    a.push_back(root->val);
    return;
  }

  solve(root->left,a);
  solve(root->right,a);
   

  }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a,b;
        solve(root1,a);
        solve(root2,b);

        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]!=b[j]){
                return false;
            }
            i++;
            j++;
        }
        return (i==a.size() && j==b.size());
    }
};