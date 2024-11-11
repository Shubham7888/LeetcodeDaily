class Solution {
public:

bool solve(int &a,int &b,vector<int>&p){
    int low=0;
    int high=p.size()-1;
   int ans=-1;
    while(low<=high){
      int mid=(low+high)/2;
      if(p[mid]>=a){
        high=mid-1;
      }else{
      //cout<<p[mid]<<endl;
        if(a-p[mid]<b){
            ans=p[mid];
            high=mid-1;
        }else{
            low=mid+1;
        }
      }
    }
   // cout<<ans<<endl;

    if(ans==-1)
    return false;
    a-=ans;
    return true;
}
    bool primeSubOperation(vector<int>& nums) {

      vector<bool> prime(1001, true);
        prime[1]=false;
        for (int p = 2; p * p <= 1000; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= 1000; i += p)
                prime[i] = false;
            }
         }
         
         vector<int>p;
         for(int i=2;i<=1000;i++){
            if(prime[i]==true){
                p.push_back(i);
            }
         }

         

         for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>=nums[i+1]){
              bool x=solve(nums[i],nums[i+1],p);
              //cout<<nums[i]<<" "<<nums[i+1]<<endl;
              if(!x)
              return false;
            }
         }

         return true;
        


    }
};