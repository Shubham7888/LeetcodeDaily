class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        pair<int,int>p;
        p.first=intervals[0][0];
        p.second=intervals[0][1];

        int count=0;

        for(int i=1;i<intervals.size();i++){
           if(intervals[i][0]>=p.first && intervals[i][0]<p.second){
              count++;
              if(intervals[i][1]<=p.second){
                p.first=intervals[i][0];
                p.second=intervals[i][1];
            
              }
           }else{
               p.first=intervals[i][0];
                p.second=intervals[i][1];
           }
        }
        return count;
    }
};