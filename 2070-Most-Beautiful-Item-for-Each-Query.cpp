class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        vector<int>pre;
        sort(items.begin(),items.end());

        int maxi=0;

        for(auto it:items){
            maxi=max(maxi,it[1]);
            pre.push_back(maxi);
        }
        vector<int>ans;

        for(auto it:queries){
            int idx=-1;

            int low=0,high=items.size()-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(items[mid][0]<=it){
                    idx=mid;
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
            if(idx==-1){
                ans.push_back(0);
            }else{
                ans.push_back(pre[idx]);
            }
        }
        return ans;
    }
};