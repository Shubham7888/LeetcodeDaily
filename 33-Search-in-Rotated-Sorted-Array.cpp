class Solution {
public:
    int search(vector<int>& nums, int t) {
         int low=0,high=nums.size()-1;

         while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==t)
            return mid;
            else if(nums[low]<=nums[mid]){
                if(t>=nums[low] && t<=nums[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else{
              if(t>=nums[mid] && t<=nums[high]){
                low=mid+1;
              }else{
                high=mid-1;
              }
            }
         }
         return -1;
    }
};