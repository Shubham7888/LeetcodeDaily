class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
         int mod=1e9+7;
        vector<int>freq(26);

        for(auto it:s){
            freq[it-'a']++;
        }

        for(int i=0;i<t;i++){
            vector<int>temp(26);
           for(int i=0;i<26;i++){
              if(i==25){
                 if(freq[i]){
                    temp[0]+=freq[i]%mod;
                    temp[1]+=freq[i]%mod;
                 }
              }else if(freq[i]){
                 temp[i+1]+=freq[i]%mod;
              }

           }
           freq=temp;
        }
        int ans=0;
       

        for(int i=0;i<26;i++){
           ans+=freq[i]%mod;
           ans%=mod;
        }
        return ans;

    }
};