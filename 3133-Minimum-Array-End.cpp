class Solution {
public:
    long long minEnd(int n, int x) {
        
        long long ans=x;
        long long count=n-1;
        long long prev=x;
        for(long long i=x+1;count>0;i=ans+1){
            if((i&prev)==x){
                prev=i;
                ans=i;
            }else{
              i|=x;
              prev=i;
              ans=prev;
            }
            count--;
        }

        return ans;

    }
};