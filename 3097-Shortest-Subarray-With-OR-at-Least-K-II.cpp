class Solution {
public:

   void takeor(vector<int>&bitset,int &orval,int n){
     
      orval|=n;

      for(int i=0;i<32;i++){
        bitset[i]+=((n&(1<<i))?1:0);
      }
   } 

   void clearor(vector<int>&bitset,int &orval,int n){
      
      for(int i=0;i<32;i++){
        bitset[i]+=((n&(1<<i))?-1:0);

        if(bitset[i]==0){
            orval=orval & (~(1<<i));
        }
      }
   }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans=INT_MAX;
        int orval=0;
        vector<int>bitset(32,0);
        int j=0;
        for(int i=0;i<nums.size();i++){
           takeor(bitset,orval,nums[i]);
           if(orval<k)
           continue;

           for(;j<=i&&orval>=k;j++){
            clearor(bitset,orval,nums[j]);
            ans=min(ans,i-j+1);
          
           }
        }
        return ans==INT_MAX?-1:ans;
    }
};