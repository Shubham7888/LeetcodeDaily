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
  bool solve(TreeNode* &root1,TreeNode* &root2){
    if(!root1 && !root2)
    return true;
     
     if(!root1 || !root2)
     return false;

    bool lefty=true;
    bool righty=true;

    if(root1->val==root2->val){
        lefty=solve(root1->left,root2->left);
        righty=solve(root1->right,root2->right);
    }else{
        return false;
    }

    if(lefty & righty==true){
        return true;
    }
    
    swap(root1->left,root1->right);
    lefty=solve(root1->left,root2->left);
    righty=solve(root1->right,root2->right);

     if(lefty & righty==true){
        return true;
    }

    return false;


  }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return solve(root1,root2);
    }
};