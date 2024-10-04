class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum=0;
        for(auto it:skill){
            sum+=it;
        }
        
        int n=skill.size();
        int req=sum/(n/2);

        if(req*(n/2)!=sum)
        return -1;

        unordered_map<int,int>mp;
      long long ans=0;
        for(auto it:skill){
          if(mp.count(req-it)){
            ans+=(it*(req-it));
            mp[req-it]--;
            if(mp[req-it]==0){
                mp.erase(req-it);
            }
          }else{
            mp[it]++;
          }
        }

        if(mp.size()>0)
        return -1;

        return ans;

    }
};