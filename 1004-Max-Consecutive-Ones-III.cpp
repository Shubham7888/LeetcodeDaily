class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;

        int i=0,j=0;

        while(j<nums.size()){
            if(nums[j]==1){
                ans=max(ans,j-i+1);
                j++;
            }else if(k!=0){
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
        return ans;
    }
};