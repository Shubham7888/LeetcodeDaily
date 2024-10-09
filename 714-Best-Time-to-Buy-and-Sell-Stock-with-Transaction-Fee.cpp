class Solution {
public:
   int dp[50001][3];
    int solve(int i,bool flag,vector<int>&nums,int &fee){
        if(i==nums.size())
        return 0;

        if(dp[i][flag]!=-1)
        return dp[i][flag];
        
        int ans=0;
        if(flag){
          ans=max(-nums[i]-fee+solve(i+1,false,nums,fee),solve(i+1,true,nums,fee));
        }else{
            ans=max(nums[i]+solve(i+1,true,nums,fee),solve(i+1,false,nums,fee));
        }
        return dp[i][flag]=ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return solve(0,true,prices,fee);
    }
};