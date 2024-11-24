class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        long long ans=0;
        int count=0,mini=1e9;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
               if(mat[i][j]<0){
                count++;
               }
               mini=min(mini,abs(mat[i][j]));
               ans+=abs(mat[i][j]);
            }
        }

        if(count%2==1){
            ans-=2*mini;
        }
        return ans;
    }
};