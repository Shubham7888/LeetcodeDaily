class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>>v;

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                v.push_back({nums[i][j],i+1});
            }
        }

        sort(v.begin(),v.end());

        unordered_map<int,int>mp;
       int a=-1e5-1;
       int b=1e5+1;

       int i=0,j=0;

       while(j<v.size()){
        mp[v[j].second]++;
        if(mp.size()==nums.size()){
            while(mp.size()==nums.size()){
                if(abs(b-a)>(v[j].first-v[i].first)){
                    a=v[i].first;
                    b=v[j].first;
                }
                mp[v[i].second]--;
                if(mp[v[i].second]==0){
                    mp.erase(v[i].second);
                }
                i++;
            }
        }
        j++;
       }

       return {a,b};


    }
};