class Solution {
public:
    bool canAliceWin(int n) {
        bool flag=false;

        int count=10;

        while(n>=count){
            n-=count;
            flag=!flag;
            count--;
        }
        return flag;
    }
};