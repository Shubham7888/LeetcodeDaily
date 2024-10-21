class Solution {
public:

 
    int minOperations(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        
        for(int i=nums.size()-2;i>=0;i--){
           if(nums[i]>nums[i+1]){
            count++;

            for(int j=2;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    nums[i]=j;
                    break;
                }
            }
            if(nums[i]>nums[i+1])
            return -1;
             
           }
        
        }
        return count;

    }
};