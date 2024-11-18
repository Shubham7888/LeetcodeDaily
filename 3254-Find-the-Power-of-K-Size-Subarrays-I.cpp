class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
        vector<int>ans;

        for(int i=k-1;i<nums.size();i++){
            bool flag=true;
            for(int j=0;j<k;j++){
              if(nums[i-j]+j!=nums[i]){
                flag=false;
                break;
              }
            }
            if(flag){
                ans.push_back(nums[i]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};