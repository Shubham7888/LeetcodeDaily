class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int>pq;

        for(auto it:nums){
            pq.push(it);
        }

        while(pq.size() && k--){
            int x=pq.top();
            pq.pop();

            ans+=x;
            x=ceil((x*1.0)/3);
            pq.push(x);
        }
        return ans;
    }
};