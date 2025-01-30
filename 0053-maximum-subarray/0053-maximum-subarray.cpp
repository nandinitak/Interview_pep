#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    long long maxSubArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long maxi = LLONG_MIN; // Use LLONG_MIN for correctness
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum > maxi)
                maxi = sum;
            if (sum < 0)
                sum = 0;
        }
        
        return maxi;
    }
};
