class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        n/=2;
        int count=0;
        int x=nums[0];
        for(auto it:nums){
            if(it==x){
                count++;
            }else{
                count--;
                if(count==0){
                    x=it;
                    count++;
                }
            }
        }
        return x;
    }
};