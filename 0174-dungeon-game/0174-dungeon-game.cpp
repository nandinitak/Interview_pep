class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();    // Number of rows
        int m = dungeon[0].size(); // Number of columns

        // DP table to store the minimum health needed at each cell
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case: Bottom-right cell (princess' room)
        dp[n - 1][m - 1] = max(1, 1 - dungeon[n - 1][m - 1]);

        // Fill the last row (moving right to left)
        for (int j = m - 2; j >= 0; j--) {
            dp[n - 1][j] = max(1, dp[n - 1][j + 1] - dungeon[n - 1][j]);
        }

        // Fill the last column (moving bottom to top)
        for (int i = n - 2; i >= 0; i--) {
            dp[i][m - 1] = max(1, dp[i + 1][m - 1] - dungeon[i][m - 1]);
        }

        // Fill the rest of the DP table (bottom to top, right to left)
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                int fromRight = max(1, dp[i][j + 1] - dungeon[i][j]);
                int fromDown = max(1, dp[i + 1][j] - dungeon[i][j]);
                dp[i][j] = min(fromRight, fromDown);
            }
        }

        // Minimum health needed at the top-left cell
        return dp[0][0];
    }
};
