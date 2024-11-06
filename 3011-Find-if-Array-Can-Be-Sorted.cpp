class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        
        int j=1;

        for(int i=1;i<nums.size();i++){
            j=i;
          while(j>0 && nums[j]<nums[j-1]){
            int a=__builtin_popcount(nums[j]);
            int b=__builtin_popcount(nums[j-1]);
            if(a==b){
                swap(nums[j],nums[j-1]);
            }else
            return false;
            j--;
          }

        }
        return true;
    }
};