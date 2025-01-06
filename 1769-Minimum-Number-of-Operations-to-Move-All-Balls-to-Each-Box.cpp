class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans(boxes.size());
       
        for(int i=0;i<boxes.size();i++){    
            for(int j=i+1;j<boxes.size();j++){
                if(boxes[j]=='1'){
                  ans[i]+=(j-i);
                }
            }

            for(int j=0;j<i;j++){
                if(boxes[j]=='1'){
                    ans[i]+=(i-j);
                }
            }
            
        }
        return ans;
    }
};