class Solution {
public:
    int maximumSwap(int num) {
        unordered_map<int,vector<int>>mp;

        string s=to_string(num);

        for(int i=0;i<s.size();i++){
            mp[s[i]-'0'].push_back(i);
        }

        for(int i=0;i<s.size();i++){
            for(int j=9;j>(s[i]-'0');j--){
                reverse(mp[j].begin(),mp[j].end());
                for(auto it:mp[j]){
                    if(it>i){
                        char c=s[i];
                        s[i]=j+'0';
                        s[it]=c;
                        return stoi(s);
                    }
                }
            }
        }
        return stoi(s);
    }
};