class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        unordered_map<long long,int>mp;
        int ans=-1;
        for(auto it:nums){
            if(mp.count((long long)it*it)){
                mp[it]=1+mp[it*it];
            }else{
                mp[it]=1;
            }
            ans=max(ans,mp[it]);
        }

        return ans==1?-1:ans;
         
    }
};