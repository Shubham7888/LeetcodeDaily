class Solution {
public:
   
   int dp[1001][1001];
   int solve(int i,int j,vector<vector<int>>&grid){
     if(i<0 || i==grid.size() || j==grid[0].size())
     return 0;

     if(dp[i][j]!=-1)
     return dp[i][j];

     int ans=0;

     if(j+1<grid[0].size() && i-1>=0 && grid[i][j]<grid[i-1][j+1]){
        ans=max(ans,1+solve(i-1,j+1,grid));
     }

     if(j+1<grid[0].size() && grid[i][j+1]>grid[i][j]){
        ans=max(ans,1+solve(i,j+1,grid));
     }

     if(i+1<grid.size() && j+1<grid[0].size() && grid[i+1][j+1]>grid[i][j]){
        ans=max(ans,1+solve(i+1,j+1,grid));
     }

     return dp[i][j]=ans;


   }
    int maxMoves(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
         int ans=0;
         for(int i=0;i<grid.size();i++){
         
                ans=max(ans,solve(i,0,grid));
        
         }
         return ans;
    }
};