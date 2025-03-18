class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxcount = 1; 
        for (int i = 0; i < n; i++) {
            int count = 1;
            int orSum = nums[i];
            
            for (int j = i + 1; j < n; j++) {
                if ((orSum & nums[j]) != 0) { 
                    break;
                } else {
                    orSum |= nums[j];  
                    count++;
                }
            }
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
};
