class Solution {
public:
  bool solve(unordered_map<char,int>&mp,int k){
    if(mp['a']<k || mp['b']<k || mp['c']<k){
        return false;
    }

    return true;
  }
    int takeCharacters(string s, int k) {
        unordered_map<char,int>mp;

        for(auto it:s){
            mp[it]++;
        }
        
        if(!solve(mp,k)){
            return -1;
        }

        int i=0,j=0,ans=-1;

        while(j<s.size()){
            mp[s[j]]--;

            while(!solve(mp,k)){
                mp[s[i]]++;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return s.size()-ans;

    }
};