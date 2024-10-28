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
  void solve(TreeNode* &root,int count,vector<int>&level){
    if(!root)
    return ;
    
    if(!root->left && !root->right)
     return ;
    
     int sum=0;
     if(root->left){
        sum+=root->left->val;
     }

     if(root->right){
        sum+=root->right->val;
     }
      
      if(root->left)
     root->left->val=level[count]-sum;

     if(root->right)
     root->right->val=level[count]-sum;

     solve(root->left,count+1,level);
     solve(root->right,count+1,level);

     

  }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int>level;

        queue<TreeNode*>q;
        q.push(root);

        while(q.size()){
            int n=q.size();
             int sum=0;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                sum+=node->val;
                
                if(node->left)
                q.push(node->left);

                if(node->right)
                q.push(node->right);
            }
            level.push_back(sum);
        }

        solve(root,1,level);
        root->val=0;
        return root;
    }

};