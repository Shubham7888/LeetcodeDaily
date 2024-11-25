class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;

        for(auto it:nums){
            st.insert(it);
        }

        int prev=0;
        int ans=0;
        int count=0;

        for(auto it:st){
            if(it==prev+1){
                count++;
            }else{
                count=1;
            }
            prev=it;
            ans=max(ans,count);
        }

        return ans;
    }
};