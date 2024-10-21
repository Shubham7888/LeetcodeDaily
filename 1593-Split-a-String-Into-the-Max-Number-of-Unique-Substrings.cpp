class Solution {
public:
  int ans=0;
  void solve(int i,string &s,unordered_set<string>&st){
    if(i>=s.size()){
        ans=max(ans,(int)st.size());
        return;
    }

    string temp="";

    for(int j=i;j<s.size();j++){
        temp+=s[j];
        if(!st.count(temp)){
            st.insert(temp);
            solve(j+1,s,st);
            st.erase(temp);
        }
    }
  }
    int maxUniqueSplit(string s) {
        unordered_set<string>st;

        solve(0,s,st);
        return ans;
    }
};