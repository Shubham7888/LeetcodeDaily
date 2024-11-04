class Solution {
public:
    string compressedString(string word) {
        int i=1;
        int count=1;
        string ans="";
       int n=word.size();
        while(i<word.size()){           
            if(word[i]==word[i-1]){
            count++;
            if(count==10){
                ans+=(9+'0');
                ans+=word[i];
                count=1;
            }
           }else{
             ans+=(count+'0');
             ans+=word[i-1];
             count=1;
           }
           i++;
        }

        ans+=(count+'0');
        ans+=word[n-1];
        return ans;
    }
};