class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        pair<int,int>p;
       vector<vector<int>>ans;
       sort(nums.begin(),nums.end());

       p.first=nums[0][0];
       p.second=nums[0][1];

       for(int i=1;i<nums.size();i++){
         if(p.second>=nums[i][0]){
           p.second=max(p.second,nums[i][1]);
         }else{
            ans.push_back({p.first,p.second});
            p.first=nums[i][0];
            p.second=nums[i][1];
         }
       }
       ans.push_back({p.first,p.second});
       return ans;

    
    }
};