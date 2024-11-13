class Solution {
public:
    long long countFairPairs(vector<int>& nums, int l, int u) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        vector<int>store;
        for(int i=0;i<nums.size();i++){
          int idx1=lower_bound(store.begin(),store.end(),l-nums[i])-store.begin();
          int idx2=upper_bound(store.begin(),store.end(),u-nums[i])-store.begin();
           idx2--;
           if(idx1<=idx2){
            ans+=(idx2-idx1+1);
           }
           store.push_back(nums[i]);
        }
        return ans;
    }
};