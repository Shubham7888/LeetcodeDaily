class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size();
        int m=box[0].size();
        vector<vector<char>>ans(m,vector<char>(n));

        for(int i=0;i<box.size();i++){
            for(int j=box[0].size()-1;j>=0;j--){
                if(box[i][j]=='#'){
                    int k=j+1;
                   while(k<box[0].size() && box[i][k]=='.'){
                    swap(box[i][k-1],box[i][k]);
                    k++;
                   }
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<box[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
      int k=0;
       for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            ans[j][k]=box[i][j];
        }
        k++;
       }
        
        return ans;
    }
};