class Solution {
public:
   void solve(int a,int b,vector<vector<int>>&grid){
     
     
      for(int i=a-1;i>=0 && (grid[i][b]==3 || grid[i][b]==0);i--){
        grid[i][b]=3;
      }
      
      for(int j=b+1;j<grid[0].size() && (grid[a][j]==3 || grid[a][j]==0) ;j++){
        grid[a][j]=3;
      }

      for(int i=a+1;i<grid.size() && (grid[i][b]==3 || grid[i][b]==0);i++){
        grid[i][b]=3;
      }

      for(int j=b-1;j>=0 && (grid[a][j]==3 || grid[a][j]==0);j--){
        grid[a][j]=3;
      }
   }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>>grid(m,vector<int>(n,0));
        for(auto it:guards){
            grid[it[0]][it[1]]=1;
        }

         for(auto it:walls){
            grid[it[0]][it[1]]=2;
        }

        for(auto it:guards){
            solve(it[0],it[1],grid);
        }

        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //cout<<grid[i][j]<<" ";
                if(grid[i][j]==0){
                    count++;
                }
            }
            //cout<<endl;
        }

        return count;

    }
};