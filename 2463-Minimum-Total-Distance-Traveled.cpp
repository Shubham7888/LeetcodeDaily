class Solution {
public:
  long long dp[101][10000];

  long long solve(int i,int j,vector<int>&robot,vector<int>&nums){
     if(i==robot.size())
     return 0;

     if(j==nums.size())
     return 1e18;

     if(dp[i][j]!=-1){
        return dp[i][j];
     }

     long long notpick=solve(i,j+1,robot,nums);
     long long pick=abs(robot[i]-nums[j])+solve(i+1,j+1,robot,nums);

     return dp[i][j]=min(pick,notpick);
  }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
         memset(dp,-1,sizeof(dp));

         vector<int>nums;
         for(auto it:factory){
            int limit=it[1];
            while(limit--){
                nums.push_back(it[0]); // to avoid keeping track of remaining limit of factory
            }
         }

         return solve(0,0,robot,nums);


    }
};