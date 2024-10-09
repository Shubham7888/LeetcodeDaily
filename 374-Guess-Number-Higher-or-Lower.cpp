/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return \t     -1 if num is higher than the picked number
 *\t\t\t      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low=0,high=n;

        while(low<=high){
            int mid=low+(high-low)/2;
            int check=guess(mid);
            if(check==0)
            return mid;
            else if(check==-1){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return -1;
    }
};