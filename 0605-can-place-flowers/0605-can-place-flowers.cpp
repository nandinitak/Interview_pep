class Solution {
public:
bool canPlaceFlowers(vector<int>& nums, int n) {
    int m = nums.size();
    int fl = 0;

    for (int i = 0; i < m; i++) {
        if ((i == 0 && nums[i] == 0 && (i + 1 == m || nums[i + 1] == 0)) || 
            (i == m - 1 && nums[i] == 0 && nums[i - 1] == 0) || 
            (nums[i] == 0 && i > 0 && i < m - 1 && nums[i - 1] == 0 && nums[i + 1] == 0)) {
                
            fl++;
            nums[i] = 1;  // Place a flower
            i++;  // Skip next index
        }
    }

    return fl >= n;



    }
};