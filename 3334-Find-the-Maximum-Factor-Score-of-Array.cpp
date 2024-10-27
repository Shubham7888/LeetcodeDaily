class Solution {
public:
 long long getgcd(long long a,long long b){
    if(b==0)
    return a;

    return getgcd(b,a%b);
 }

 long long getlcm(long long a,long long b){
    return (a*b)/getgcd(a,b);
 }
    long long maxScore(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        long long lcm=nums[0],gcd=nums[0];
        for(int i=1;i<n;i++){
           gcd=getgcd(gcd,(long long)nums[i]);
           lcm=getlcm(lcm,nums[i]);
        }
        ans=lcm*gcd;
        cout<<ans<<endl;
        for(int i=0;i<n;i++){
            long long lcm1=0,gcd1=0;
            for(int j=0;j<n;j++){
                if(i==j)
                continue;
                if(lcm1==0){
                    lcm1=nums[j];
                 gcd1=nums[j];
                }else{
                gcd1=getgcd(gcd1,(long long)nums[j]);
                lcm1=getlcm(lcm1,nums[j]);
                }
            }
            ans=max(ans,gcd1*lcm1);
        }
        return ans;
    }
};