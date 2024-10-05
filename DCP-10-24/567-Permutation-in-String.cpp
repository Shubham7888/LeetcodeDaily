class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       if(s1.size()>s2.size())
       return false;

        unordered_map<char,int>mp;
          unordered_set<char>st(s1.begin(),s1.end());
        for(auto it:s1){
            mp[it]++;
        }

        int k=s1.size();

        int i=0,j=0;

        for(;j<k;j++){
            if(st.count(s2[j])){
                mp[s2[j]]--;
                if(mp[s2[j]]==0){
                  mp.erase(s2[j]);
                }
            }
        }

        if(mp.size()==0)
        return true;

        for(int i=k;i<s2.size();i++){

              if(st.count(s2[i-k])){
                mp[s2[i-k]]++;
                if(mp[s2[i-k]]==0){
                    mp.erase(s2[i-k]);
                }
            }

            if(st.count(s2[i])){
                mp[s2[i]]--;
                 if(mp[s2[i]]==0){
                  mp.erase(s2[i]);
                }
            }


             if(mp.size()==0)
             return true;

        }

        return false;


        while(j<s2.size()){

        }

    }
};
