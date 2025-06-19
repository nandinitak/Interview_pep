class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = nums[0];

        int product = 1;
        // Forward pass
        for (int i = 0; i < n; i++) {
            product *= nums[i];
            maxProduct = max(maxProduct, product);
            if (product == 0) product = 1; // reset if zero
        }

        product = 1;
        // Backward pass
        for (int i = n - 1; i >= 0; i--) {
            product *= nums[i];
            maxProduct = max(maxProduct, product);
            if (product == 0) product = 1; // reset if zero
        }

        return maxProduct;
    }
};
