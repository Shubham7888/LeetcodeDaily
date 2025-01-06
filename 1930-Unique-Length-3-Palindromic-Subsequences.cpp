class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>>v(26,{-1,-1});

        int ans=0;

        for(int i=0;i<s.size();i++){
            if(v[s[i]-'a'].first==-1){
                v[s[i]-'a'].first=i;
            }
            v[s[i]-'a'].second=i;
        }

        for(int i=0;i<26;i++){
            int f=v[i].first;
            int se=v[i].second;
            if(f==-1)
            continue;
            unordered_set<char>mp;
            for(int j=f+1;j<se;j++){
                mp.insert(s[j]);
            }
            ans+=mp.size();
        }
        return ans;

    }
};