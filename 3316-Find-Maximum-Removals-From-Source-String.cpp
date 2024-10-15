class Solution {
public:
   int dp[3004][3004];
   unordered_set<int>st;

   int solve(int i,int j,string &s,string &t){
     if(i==s.size() && j==t.size())
     return 0;

     if(i==s.size()){
        return INT_MIN;
     }

   if(dp[i][j]!=-1)
   return dp[i][j];

   int notpick=INT_MIN;
   int rem=INT_MIN;

   int pick=INT_MIN;

   notpick=solve(i+1,j,s,t);
   
   if(s[i]==t[j])
   pick=solve(i+1,j+1,s,t);

   if(st.count(i)){
    rem=1+solve(i+1,j,s,t);
   }
  

   return dp[i][j]=max({rem,notpick,pick});

   }
    int maxRemovals(string s, string t, vector<int>& nums) {
        int n=nums.size();
        
        for(auto it:nums){
            st.insert(it);
        }

        memset(dp,-1,sizeof(dp));

        return solve(0,0,s,t);


    }
};