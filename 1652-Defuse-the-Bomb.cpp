class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>ans(n);
        for(int i=0;i<code.size();i++){
            if(k>0){
                int c=0;
                int j=(i+1)%n;
                int sum=0;
                while(c<k){
                  sum+=code[j];
                  j++;
                  j=j%n;
                  c++;
                }
                ans[i]=sum;
            }else if(k<0){
                int c=0;
                int j=i-1;
                int sum=0;
                while(c<abs(k)){
                    j=j==-1?(n-1):j;
                    sum+=code[j];
                    j--;
                    c++;
                }
                ans[i]=sum;

            }else{
                ans[i]=0;
            }
            
        }
        return ans;
    }
};