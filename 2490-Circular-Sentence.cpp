class Solution {
public:
    bool isCircularSentence(string s) {
        vector<string>v;

        string temp="";
        int i=0;
        while(i<s.size()){
            if(s[i]==' ' || i==s.size()-1){
                if(i==s.size()-1){
                    temp+=s[i];
                }
                int n=v.size();
                if(n){
                   string x=v[n-1];
                   if(x[x.size()-1]!=temp[0]){
                    //cout<<x<<" "<<temp<<endl;
                    return false;
                   }
                }
                v.push_back(temp);
                temp="";
            }else{

               temp+=s[i];
            }
            i++;
        }
        int n=v.size();
        int m=v[n-1].size();
        //cout<<v[0]<<" "<<v[n-1]<<endl;
        return v[0][0]==v[n-1][m-1];
    }
};