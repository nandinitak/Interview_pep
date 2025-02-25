class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
   int n = nums.size();
    long long result=0;
    int mod=1000000000+7;
    int prefix = 0, even = 1, odd = 0;
    
    for(int i = 0; i < n; i++) {
        prefix += nums[i];

        if(prefix % 2 == 0) {
            result += odd;  // Count subarrays with odd sum
            even++;         // Increment even count
        } else {
            result += even; // Count subarrays with even sum
            odd++;          // Increment odd count
        }
    }
    return result%mod;

    }
};