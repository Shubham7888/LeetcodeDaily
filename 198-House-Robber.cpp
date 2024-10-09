class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];

        vector<int>dp(n+1);
        
        dp[0]=nums[0];
        dp[1]=nums[1];
       int ans=max(dp[0],dp[1]);
        for(int i=2;i<n;i++){
            dp[i]=nums[i];
            int maxi=0;
            for(int j=i-2;j>=0;j--){
                maxi=max(dp[j],maxi);
                ans=max(ans,maxi+dp[i]);
            }
            dp[i]+=maxi;
        }

        return ans;

    }
};