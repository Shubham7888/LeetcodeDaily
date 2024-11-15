class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
    
        int left = 0;
        while (left < n - 1 && arr[left] <= arr[left + 1]) {
            left++;
        }
    
        if (left == n - 1) {
            return 0;
        }
      
        int right = n - 1;
        while (right > left && arr[right] >= arr[right - 1]) {
            right--;
        }

        int ans = min(n - left - 1, right);

        for (int i = 0; i <= left; i++) {
            while (right < n && arr[i] > arr[right]) {
                right++;
            }
            if (right < n) {
                ans = min(ans, right - i - 1);
            }
        }
        
        return ans;
    }
};