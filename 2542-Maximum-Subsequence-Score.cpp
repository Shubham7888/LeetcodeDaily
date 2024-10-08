class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums1.size();i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.rbegin(),v.rend());

        priority_queue<int,vector<int>,greater<int>>pq;

        int i=0,j=0;
        long long ans=0,sum=0;
        while(j<v.size()){
           sum+=v[j].second;
           pq.push(v[j].second);
           if(j-i+1==k){
           ans=max(ans,sum*v[j].first);
           sum-=pq.top();
           pq.pop();
           i++;
           }
           j++;
        }
        return ans;
    }
};