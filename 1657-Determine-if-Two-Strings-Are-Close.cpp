class Solution {
public:
    bool closeStrings(string s, string t) {
        int n=s.size();
        int m=t.size();

        if(n!=m){
            return false;
        }

        unordered_map<char,int>mp1,mp2;
        for(auto it:s){
            mp1[it]++;
        }

        for(auto it:t){
            if(!mp1.count(it))
            return false;

            mp2[it]++;
        }

     unordered_map<int,int>c;

     for(auto it:mp1){
        c[it.second]++;
     }

     for(auto it:mp2){
        if(!c[it.second]){
            return false;
        }

        c[it.second]--;

        if(c[it.second]==0)
        c.erase(it.second);

     }

     return !c.size();



         
    }
};