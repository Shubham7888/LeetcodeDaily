class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>mp;

        for(auto it:arr){
            if(it%2==0){
                if(mp.count(it/2))
                return true;
            }

            if(mp.count(it*2))
            return true;

            mp[it]++;
        }
        return false;
    }
};