class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int no = 0; // Count breaks in sorted order

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) { // Check where order breaks
                no++;
            }
        }
        
        // Check last element with first element (circular array condition)
        if (nums[n - 1] > nums[0]) {
            no++;
        }

        return (no <= 1); // If sorted breaks <= 1, it's a rotated sorted array
    }
};
