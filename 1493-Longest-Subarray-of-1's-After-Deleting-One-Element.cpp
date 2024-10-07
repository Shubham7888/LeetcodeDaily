class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k=1;

        int ans=0;
        int i=0,j=0;

        while(j<nums.size()){
           if(nums[j]==1){
            ans=max(ans,j-i+1);
            j++;
           }else if(k){
             k--;
             ans=max(ans,j-i+1);
             j++;
           }else{
              while(nums[i]==1){
                i++;
              }
              k++;
              i++;
           }

        }
        return ans!=0?ans-1:ans;
    }
};