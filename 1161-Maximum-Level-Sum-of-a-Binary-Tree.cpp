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
    int maxLevelSum(TreeNode* root) {
        int ans=0;
       int temp=INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        int count=1;
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
            if(sum>temp){
                temp=sum;
                ans=count;
            }
            count++;
        }
        return ans;
    }
};