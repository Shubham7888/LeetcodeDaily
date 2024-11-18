class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size();
        vector<int>temp(n+1);

        for(auto it:q){
            int l=it[0];
            int r=it[1];
            temp[l]--;
            temp[r+1]++;
        }
        int sum=0;
        for(int i=0;i<n;i++){
             sum+=temp[i];
            nums[i]+=sum;
            if(nums[i]>0){
                return false;
            }
        }
        return true;
    }
};