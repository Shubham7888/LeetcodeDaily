class Solution {
public:
   
   int solve(int x,int n,vector<int>nums){
     int sum=0;

     if(x==0)
     return 1e9;

     for(auto it:nums){
        if(x>=it){
            sum+=1;
        }else{
            sum+=ceil((it*1.0)/x);
        }
     }
     //cout<<sum<<" "<<x<<endl;
     return sum;
   }

    int minimizedMaximum(int n, vector<int>& nums) {
        int ans=1e9;

        int low=0,high=1e9;

        while(low<=high){
            int mid=low+(high-low)/2;
            int x=solve(mid,n,nums);

            if(x<=n){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
          
              
        }
        return ans;
    }
};