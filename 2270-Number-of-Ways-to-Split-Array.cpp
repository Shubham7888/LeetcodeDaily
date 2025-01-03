class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum1=0,sum2=0;
        for(int i=0;i<nums.size()-1;i++){
            sum1+=nums[i];
        }
        sum2+=nums[nums.size()-1];
        int j=nums.size()-2;
        int ans=0;
        while(j>=0){
            if(sum1>=sum2){
                ans++;
            }
            //cout<<sum1<<" "<<sum2<<endl;
            if(nums[j]>=0){
                sum1-=nums[j];
            }else{
                sum1+=abs(nums[j]);
            }
            sum2+=nums[j];
            j--;
        }
        return ans;
    }
};