class Solution {
public:
    int smallestNumber(int n, int t) {
        
        for(int i=n;i<1e5;i++){
            int x=i;
            int prod=1;
            while(x){
              int rem=x%10;
              prod*=rem;
              x/=10;
            }
            if(prod%t==0){
                return i;
            }
        }
        return 1;
    }
};