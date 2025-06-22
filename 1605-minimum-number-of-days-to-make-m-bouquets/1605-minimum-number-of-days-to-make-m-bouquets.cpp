class Solution {
public:
    bool func(vector<int>& nums, int mid, int n, int m, int k) {
        int count = 0;
        int bouquets = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] <= mid) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        // Use 1LL to prevent overflow
        if (1LL * m * k > n) return -1;

        int days = -1;
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (func(nums, mid, n, m, k)) {
                days = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return days;
    }
};
