class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size(),0);

        int idxp=0,idxn=1;
         for(auto it:nums){
            if(it>0){
                ans[idxp]=it;
                idxp+=2;
            }else{
                ans[idxn]=it;
                idxn+=2;
            }
         }

         return ans;
    }
};