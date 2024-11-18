class Solution {
public:

bool solve(int k,vector<int>nums,vector<vector<int>>&q){
    int n=nums.size();
     vector<int>temp(n+1);
  
        for(int i=0;i<k;i++){
            int l=q[i][0];
            int r=q[i][1];
            int val=q[i][2];
            temp[l]-=val;
            temp[r+1]+=val;
        }
        int sum=0;
        for(int i=0;i<n;i++){
             sum+=temp[i];
             if(nums[i]<=0)
             continue;
            nums[i]+=sum;
            if(nums[i]>0){
                return false;
            }
        }
        return true;

}
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
 
        int n=nums.size();
      
        int low=0,high=q.size();
        int ans=1e9;
        while(low<=high){
            int mid=(low+high)/2;
            //cout<<mid<<endl;
            if(solve(mid,nums,q)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        if(ans==1e9)
        return -1;

        return ans;

    }
};