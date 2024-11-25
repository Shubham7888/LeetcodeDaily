class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int i=0,j=0;
        int sum=0;
       int ans=1e9;
        while(j<nums.size()){
          sum+=nums[j];
          while(sum>=t){
            ans=min(ans,j-i+1);
            sum-=nums[i];
            i++;
          }
          j++;
        }
        return ans==1e9?0:ans;
    }
};