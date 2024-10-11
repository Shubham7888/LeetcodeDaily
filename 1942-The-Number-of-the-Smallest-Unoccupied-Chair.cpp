class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int t) {

        vector<pair<pair<int,int>,int>>nums;
         int i=0;
        for(auto it:times){
          nums.push_back({{it[0],it[1]},i++});
        }
      
      sort(nums.begin(),nums.end());

    //   for(auto it:nums){
    //     cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<endl;
    //   }

      
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     priority_queue<int,vector<int>,greater<int>>emptychair;
      int count=0;

      for(int i=0;i<nums.size();i++){
         if(!pq.size()){
            pq.push({nums[i].first.second,count++});
             if(nums[i].second==t)
                return count-1;
         }else{
             if(nums[i].first.first>=pq.top().first){
              while(pq.size() && nums[i].first.first>=pq.top().first){
                emptychair.push(pq.top().second);
                pq.pop();
              }
              int chair=emptychair.top();
              emptychair.pop();

              pq.push({nums[i].first.second,chair});

                if(nums[i].second==t){
                 return chair;
                }
            }else{
                if(emptychair.size()){
                      int chair=emptychair.top();
                       emptychair.pop();
                    pq.push({nums[i].first.second,chair});
                     if(nums[i].second==t)
                return chair;
                }
                else
                pq.push({nums[i].first.second,count++});
                
                if(nums[i].second==t)
                return count-1;
            }
         }
      }

      return count-1;

    }
};