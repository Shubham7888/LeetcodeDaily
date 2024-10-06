class Solution {
public:
  void solve(int i,vector<vector<int>>&adj,vector<int>&vis){
    vis[i]=1;

    for(auto it:adj[i]){
        if(vis[it]==0){
            solve(it,adj,vis);
        }
    }
  } 


    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edge) {
        vector<vector<int>>adj(n);

        for(auto it:edge){
            adj[it[0]].push_back(it[1]);
        }
       
       vector<int>vis(n);

       solve(k,adj,vis);

       bool flag=false;
      

       for(int i=0;i<n;i++){
          if(vis[i]==0){
            for(auto it:adj[i]){
                if(vis[it]==1){
                    flag=true;
                    break;
                }
            }
            if(flag){
                break;
            }
          }
       }

    //    for(auto it:vis){
    //     cout<<it<<" ";
    //    }
    //    cout<<endl;

    //    for(auto it:vis2){
    //     cout<<it<<" ";
    //    }
    //    cout<<endl;

   vector<int>ans;
       if(flag){
        for(int i=0;i<n;i++){
            ans.push_back(i);
        }
        return ans;
       }

       for(int i=0;i<n;i++){
          if(vis[i]==0){
            ans.push_back(i);
          }
       }
       return ans;

    }
};