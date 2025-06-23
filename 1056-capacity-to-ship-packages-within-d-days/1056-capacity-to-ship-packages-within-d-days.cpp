class Solution {
public:
    int shipWithinDays(vector<int>& nums, int days) {
        int n = nums.size();
        int l = *max_element(nums.begin(), nums.end());

        int h = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        while (l <= h) {
            int mid = (l + h) / 2;
            int din = 1;
            
                int weight = 0;
            for (int i = 0; i < n; i++) {
                if (weight + nums[i] > mid) {
                    weight = 0;
                    din++;
                }
                weight += nums[i];
            }
            if (din <= days) {
                ans = mid;
                h = mid - 1;
            } else
                l = mid + 1;
        }
    

 return ans;
}
};