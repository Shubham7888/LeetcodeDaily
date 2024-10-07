class Solution {
public:
    int minLength(string s) {
        stack<char>st;

        for(auto it:s){
            if(st.size()==0){
                st.push(it);
            }else{
               if(it=='B'){
                 if(st.top()=='A'){
                    st.pop();
                 }else{
                    st.push(it);
                 }
               }else if(it=='D'){
                 if(st.top()=='C'){
                    st.pop();
                 }else{
                    st.push(it);
                 }
               }else{
                st.push(it);
               }
                 
            }
        }

        return (int)st.size();
    }
};
