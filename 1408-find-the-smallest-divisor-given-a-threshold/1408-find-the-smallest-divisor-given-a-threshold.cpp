class Solution {
public:
    int smallestDivisor(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 1;
        int h = *max_element(nums.begin(), nums.end());
        int ans;
        int sum;
        while (l <= h) {
            int mid = (l + h) / 2;
            sum =0;
            for (int i = 0; i < n; i++) {
                sum += (nums[i] + mid - 1) / mid;
            }
            if (sum <= k) {
                h = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};