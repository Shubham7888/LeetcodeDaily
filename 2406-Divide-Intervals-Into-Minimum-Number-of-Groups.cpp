class Solution {
public:
    int minGroups(vector<vector<int>>& inter) {
        int n=inter.size();
        if(n==0)
            return 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(inter.begin(),inter.end());
        pq.push(inter[0][1]);
        
        for(int i=1;i<n;i++){
            if(inter[i][0]<=pq.top())
                pq.push(inter[i][1]);
            else{
                pq.pop();
                pq.push(inter[i][1]);
            }
        }
        return pq.size();
    }
};