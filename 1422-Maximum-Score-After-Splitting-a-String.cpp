class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
     int one=0;
        for(auto it:s){
            if(it=='1'){
                one++;
            }
        }
    int ans=0,zero=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1'){
                one--;
            }else{
                zero++;
            }
            ans=max(ans,zero+one);
        }

        return ans;


    }
};