class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int x) {
        int temp=pow(2,x);
        temp--;
        
        int p=0;
        for(auto it:nums){
          p^=it;
        }

        //  p^k=temp;

        vector<int>ans;

        for(int i=nums.size()-1;i>=0;i--){
            ans.push_back(temp^p);
            p^=nums[i];
        }
        return ans;


    }
};