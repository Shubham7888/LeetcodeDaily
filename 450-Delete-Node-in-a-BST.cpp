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
    void solve(TreeNode* &root,int key){
        if(!root)
        return;
      
      if(root->val==key){
        if(root->left){
            TreeNode* curr=root->right;
            root=root->left;
            TreeNode* temp=root;
            while(temp && temp->right){
                temp=temp->right;
            }
            temp->right=curr;
          
        }else{
            root=root->right;
        }
      }
      if(root && root->left)
      solve(root->left,key);

      if(root && root->right)
      solve(root->right,key);

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
         solve(root,key);
         return root;
    }
};