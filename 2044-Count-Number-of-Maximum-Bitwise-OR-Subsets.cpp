class Solution {
public: 

   int solve(int i,int temp,int maxi,vector<int>&nums){
      if(i>=nums.size())
      return 0;
      
      int ans=0;

      if((temp|nums[i])==maxi){
        ans++;
      }

      ans+=solve(i+1,temp|nums[i],maxi,nums);
      ans+=solve(i+1,temp,maxi,nums);

      return ans;

   }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0;

        for(auto it:nums){
            maxi|=it;
        }
        
        return solve(0,0,maxi,nums);

    }
};