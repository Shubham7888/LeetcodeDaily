class Solution {
public:

    string gen(int length){
        if(length<=0)return "";
        string ans="";
        for(int i=0;i<length;i++)ans+='*';
        return ans;
    }

    bool handle_front(string s1,string s2){
        int n=s1.length(),m=s2.length(),skip_length=n-m;
        int i=0, j=0;
        string s3=gen(skip_length-1)+" "+s2;

        while(i<n){
            if(s1[i]==s3[j] or s3[i]=='*'){
                i++;
                j++;
            }
            else return false;
        }
        return true;
    }

    bool handle_back(string s1,string s2){
        int n=s1.length(),m=s2.length(),skip_length=n-m;
        int i=0, j=0;
        string s3=s2+" "+gen(skip_length-1);

        while(i<n){
            if(s1[i]==s3[j] or s3[i]=='*'){
                i++;
                j++;
            }
            else return false;
        }
        return true;
    }

    bool handle_edge_case(string s1,string s2){
        return handle_front(s1,s2) or handle_back(s1,s2);
    }

    bool is_matching(string &s1,string &s2,int skip_index){
        int n=s1.length(),m=s2.length(),skip_length=n-m-1;
        int i=0, j=0;
        string s3=s2.substr(0,skip_index+1)+gen(skip_length)+s2.substr(skip_index);
        cout<<"For skip_index: "<<skip_index<< " and s3: "<<s3<<endl;

        while(i<n){
            if(s1[i]==s3[j] or s3[i]=='*'){
                i++;
                j++;
            }
            else return false;
        }
        return true;
    }

    bool solve(string s1,string s2){
        int n=s1.length(),m=s2.length();
        // Agar match from start then---> options: middle/end
        //Agar match from middle: We can only add in front , so it should match till end

        //So finally 3 caser: Add at end / middle /start
        //Isse bhi easy ek tareek hai
        // assume we skip extra length har ' ' par and match remaining

        // bool is_case1=compute_case1(s1,s2);
        // bool is_case2=compute_case2(s1,s2);
        cout<<s1<<" and "<<s2<<endl;

        for(int i=0;i<=s2.length();i++){
            if(s2[i]==' '&& is_matching(s1,s2,i))return true;
        }
        bool res=handle_edge_case(s1,s2);
        return res;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int n=sentence1.length(),m=sentence2.length();
        if(n==m)return sentence1==sentence2;
        if(sentence1.length()<sentence2.length())swap(sentence1,sentence2);
        return solve(sentence1,sentence2);
    }
};