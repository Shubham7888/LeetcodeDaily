class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        
        int ans=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(i>0 && j>0 && mat[i][j]==1){
                    mat[i][j]=1+min({mat[i-1][j-1],mat[i-1][j],mat[i][j-1]});
                }

                ans+=mat[i][j];
            }
        }
        return ans;
    }
};