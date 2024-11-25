class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        
        for(auto it:strs){
            string temp=it;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(it);
        }
        vector<vector<string>>ans;

        for(auto it:mp){
            vector<string>temp;
            for(auto tt:it.second){
                temp.push_back(tt);
            }
            ans.push_back(temp);
        }
        return ans;

    }
};