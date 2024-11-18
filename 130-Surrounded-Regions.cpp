class Solution {
public:
  
  void solve(int i,int j,vector<vector<char>>&board){
     if(i<0 || i==board.size() || j<0 || j==board[0].size() || board[i][j]!='O')
     return;

     board[i][j]='*';
     solve(i+1,j,board);
     solve(i-1,j,board);
     solve(i,j+1,board);
     solve(i,j-1,board);
  }
    void solve(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                solve(i,0,board);
            }
            if(board[i][m-1]=='O'){
                solve(i,m-1,board);
            }
        }

        for(int i=1;i<m-1;i++){
            if(board[0][i]=='O'){
                solve(0,i,board);
            }

            if(board[n-1][i]=='O'){
                solve(n-1,i,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='*'){
                    board[i][j]='O';
                }else{
                    board[i][j]='X';
                }
            }
        }
        
    }
};