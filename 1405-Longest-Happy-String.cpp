class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;

        pq.push({a,'a'});
        pq.push({b,'b'});
        pq.push({c,'c'});

        string ans="";

        while(pq.size()){
            int n=ans.size();
             int count=pq.top().first;
             char p=pq.top().second;
             pq.pop();
             if(count<=0)
             continue;
            if(n==0){            
                if(count>=2){
                    ans+=p;
                    ans+=p;
                    count-=2;
                }else{
                    count--;
                    ans+=p;
                }
            }else{
               if(ans[n-1]==p){
                 if(pq.size()){
                    char o=pq.top().second;
                    int u=pq.top().first;
                    pq.pop();
                    if(u>0){
                    ans+=o;
                    pq.push({u-1,o});
                    }
                 }else
                 break;
               }else{
                   if(count>=2){
                    ans+=p;
                    ans+=p;
                    count-=2;
                }else{
                    count--;
                    ans+=p;
                }
               }
            }
             
             pq.push({count,p});
                   
        }

        return ans;
    }
};