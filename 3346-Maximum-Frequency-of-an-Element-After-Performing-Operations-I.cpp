class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int op) {
        unordered_map<int,int>freq;
        vector<pair<int,int>>event;
        for(auto it:nums){
          freq[it]++;
          event.push_back({it-k,1});
          event.push_back({it+k,2});
          event.push_back({it,3});
        }
        sort(event.begin(),event.end());
     
        int count=0;
        int ans=0;

        for(auto it:event){
            //cout<<it.second<<" "<<it.first<<endl;
            if(it.second==1){
                count++;
            }else if(it.second==2){
                count--;
            }

            int reqop=count-freq[it.first];
            ans=max(ans,freq[it.first]+min(op,reqop));
            //cout<<ans<<" "<<count<<endl;
        }

        return ans;

    }
};