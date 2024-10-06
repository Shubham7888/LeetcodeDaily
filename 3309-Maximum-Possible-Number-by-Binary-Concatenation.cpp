class Solution {
public:
 int getNumber(string &s){
   //cout<<s<<" ";
    reverse(s.begin(),s.end());

    int i=0;
    int ans=0;
    for(auto it:s){
        int x=pow(2,i);
        cout<<x<<" ";
        ans+=x*(it-'0');
        i++;
    }
    //cout<<" "<<ans<<endl;
    return ans;
 }
  string getbinary(int x){
    int y=x;
    string s="";
    while(y){

      s=to_string(1&y)+s;
      y/=2;      
    }
   //cout<<s<<endl;
    return s;

  }
    int maxGoodNumber(vector<int>& nums) {
        
        vector<string>temp;
        for(auto it:nums){
            string s="";
            s=getbinary(it);
            temp.push_back(s);
        }

        cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<" ";
    
        int ans=0;
     

        for(int i=0;i<3;i++){
            string a=temp[i];
            for(int j=0;j<3;j++){
                if(j==i)
                continue;
              string b=a+temp[j];
                
                for(int k=0;k<3;k++){
                    if(k==i || k==j)
                    continue;
                  string c=b+temp[k];
                    ans=max(ans,getNumber(c));

                }
            }
        }

        return ans;
 
    }
};