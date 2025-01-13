class Solution {
public:

 bool isPrefixAndSuffix(string &a,string &b){
    if(a.size()>b.size()){
        return false;
    }
    int i=0,j=0;

    while(i<a.size()){
        if(a[i]!=b[j]){
            return false;
        }
        i++;j++;
    }
    i=a.size()-1;
    j=b.size()-1;
    while(i>=0){
        if(a[i]!=b[j]){
            return false;
        }
        i--;j--;
    }
    return true;
 }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;

        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(isPrefixAndSuffix(words[i],words[j])){
                    ans++;
                }
            }
        }
        return ans;
    }
};