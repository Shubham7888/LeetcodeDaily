class Solution {
public:
  int dp[505][505];
   int solve(int i,int j,string &s,string &t){
     if(i==s.size() && j==t.size())
     return 0;
     
     if(j==t.size()){
        return s.size()-i;
     }else if(i==s.size()){
        return t.size()-j;
     }

     if(dp[i][j]!=-1)
     return dp[i][j];
    
    int ans=0;
     if(s[i]==t[j]){
        ans=solve(i+1,j+1,s,t);
     }else{
        ans=1+min({solve(i,j+1,s,t),solve(i+1,j,s,t),solve(i+1,j+1,s,t)});
     }

     return dp[i][j]=ans;

   }
    int minDistance(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
    }
};