class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxin = 1;
        int maxup = 1;
        int in = 1;
        int up = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
          
         
            if (nums[i] > nums[i - 1]) {
                in += 1;
                up = 1;
            } else if (nums[i] < nums[i - 1]) {
                up++;
                in = 1;
            } else {
                up = 1;
                in = 1;
            }

            maxin = max(in, maxin);
            maxup = max(up, maxup);
        }
        return max(maxin, maxup);
    }
};