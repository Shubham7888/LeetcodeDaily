class Solution {
public:
    long long totalCost(vector<int>& cost, int k, int c) {
        priority_queue<int,vector<int>,greater<int>>pq1,pq2;
       
       int i=0,j=cost.size()-1;
       for(;i<c;i++){
        pq1.push(cost[i]);
       }
       i--;
       for(;j>i;j--){
         pq2.push(cost[j]);
         if(pq2.size()==c)
         break;
       }

    if(i==j)
    j++;

       long long ans=0;

       while(i<j && pq1.size() && pq2.size()){
         if(pq1.top()<=pq2.top()){
            ans+=pq1.top();
            pq1.pop();
            i++;
            k--;
            if(i==j)
            break;
            else
            pq1.push(cost[i]);
         }else{
            ans+=pq2.top();
            pq2.pop();
            j--;
            k--;
            if(i==j)
            break;
            pq2.push(cost[j]);
         }
         
         if(k==0){
            return ans;
         }
         if(i==j){
           break;
         }
       }

       if(k==0){
            return ans;
         }
         
        // cout<<ans<<endl;

       while(pq1.size() || pq2.size()){
         if(pq1.size() && pq2.size()){
            if(pq1.top()<=pq2.top()){
                ans+=pq1.top();
                pq1.pop();
            }else{
                ans+=pq2.top();
                pq2.pop();
            }
         }else if(pq1.size()){
            ans+=pq1.top();
            pq1.pop();
         }else{
            ans+=pq2.top();
            pq2.pop();
         }

         k--;
        // cout<<ans<<" "<<k<<endl;
         if(k==0)
         return ans;
       }

       return ans;

    }
};