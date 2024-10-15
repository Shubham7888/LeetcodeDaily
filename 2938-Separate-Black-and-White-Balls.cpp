class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        vector<int>temp;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                temp.push_back(i);
            }
        }

        int val=0;

        for(auto it:temp){
            ans+=it-val;
            val++;
        }
        return ans;
    }
};