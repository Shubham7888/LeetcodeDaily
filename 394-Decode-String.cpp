class Solution {
public:
    string decodeString(string s) {
        stack<int>num;
        stack<string>st;
        int count=0;
        string ans=\\;

        for(auto it:s){
            if(isdigit(it)){
                count=count*10+it-'0';
            }else if(isalpha(it)){
                ans+=it;
            }else if(it=='['){
                num.push(count);
                st.push(ans);
                count=0;
                ans=\\;
            }else{
                int x=num.top();
                num.pop();
                cout<<x<<endl;
                string temp=ans;
                while(x>1){
                    ans+=temp;
                    x--;
                }
               ans=st.top()+ans;
               st.pop();
            }
        }
        return ans;
    }
};