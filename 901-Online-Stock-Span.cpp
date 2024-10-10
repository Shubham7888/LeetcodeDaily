class StockSpanner {
public:
  stack<pair<int,int>>st;
  int count=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        count++;

        while(st.size() && st.top().first<=price){
            st.pop();
        }

        if(!st.size()){
            st.push({price,count});
            return count;
        }
        else{
            int ans=count-st.top().second;
            st.push({price,count});
            return ans;
        }

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */