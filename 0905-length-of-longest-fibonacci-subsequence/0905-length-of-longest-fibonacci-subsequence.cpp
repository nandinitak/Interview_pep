

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index; // Maps arr values to their indices
        vector<vector<int>> dp(n, vector<int>(n, 0)); // DP table initialized to 0
        int maxlen = 0;

        // Store the index of each element
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        // Iterate over all pairs (i, j) where i < j
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int target = arr[i] + arr[j]; // Expected next Fibonacci-like number

                if (index.count(target)) {
                    int k = index[target]; // Get the index of arr[k] = arr[i] + arr[j]

                    // Update DP table
                    dp[j][k] = dp[i][j] > 0 ? dp[i][j] + 1 : 3;

                    // Update max length
                    maxlen = max(maxlen, dp[j][k]);
                }
            }
        }

        return maxlen;
    }
};

