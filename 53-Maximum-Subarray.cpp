class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int ans=-1e5;

        for(auto it:nums){
            sum+=it;
            ans=max(sum,ans);

            if(sum<0)
            sum=0;
        }
        return ans;
    }
};