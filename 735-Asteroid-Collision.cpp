class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int>st;

        for(auto it:nums){
            if(!st.size() || it>0){
                st.push(it);
            }
            else{
                while(st.size() && it<0 && st.top()>0){
                   if(abs(it)>st.top()){
                    st.pop();
                   }else{
                    break;
                   }
                }
                
                if(st.size() &&(st.top()==-1*it))
                st.pop();
                else{
                    if(!st.size() || st.top()<0)
                    st.push(it);
                }

            }
        }
        vector<int>ans;

        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};