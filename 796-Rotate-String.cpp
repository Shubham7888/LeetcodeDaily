class Solution {
public:
    bool rotateString(string s, string t) {
        
        int n=s.size();
        int m=t.size();
        if(n!=m)
        return false;

        vector<int>v;
        for(int i=0;i<t.size();i++){
            if(t[i]==s[0]){
                v.push_back(i);
            }
        }

        for(auto it:v){
            int i=0;
            bool flag=true;
            while(it<t.size()){
                if(s[i]!=t[it])
                {
                    flag=false;
                    break;
                }
                i++;
                it++;
            }
            if(flag){
                it=0;
                while(i<s.size()){
                  if(s[i]!=t[it]){
                    flag=false;
                    break;
                  }
                  i++;
                  it++;
                }
            }
            if(flag)
            return true;

        }

        return false;
    }
};