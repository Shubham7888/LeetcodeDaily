class Solution {
public: 
  int solve(int val,vector<int>&potions,long long k){
      int low=0,high=potions.size()-1;
     int ans=0;
      while(low<=high){
        int mid=low+(high-low)/2;
        if((long long)val*potions[mid]>=k){
            ans=mid+1;
           low=mid+1;
        }else{
            high=mid-1;
        }
      }

      return ans;

  }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long k) {
        sort(potions.rbegin(),potions.rend());
        vector<int>ans;
        for(auto it:spells){
            int x=solve(it,potions,k);
            ans.push_back(x);
        }

        return ans;

    }
};