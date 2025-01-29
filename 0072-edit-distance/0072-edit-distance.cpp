class Solution {
public:
    vector<vector<int>> dp; // Memoization table

    int func(string &word1, string &word2, int i, int j) {
        if (i < 0) return j + 1; // Insert all remaining characters of word2
        if (j < 0) return i + 1; // Delete all remaining characters of word1

        if (dp[i][j] != -1) return dp[i][j]; // Return already computed result

        if (word1[i] == word2[j]) 
            return dp[i][j] = func(word1, word2, i - 1, j - 1); // No operation needed

        return dp[i][j] = 1 + min({ 
            func(word1, word2, i - 1, j - 1), // Replace
            func(word1, word2, i - 1, j),     // Delete
            func(word1, word2, i, j - 1)      // Insert
        });
    }

    int minDistance(string word1, string word2) {
        int s1 = word1.length();
        int s2 = word2.length();
        dp = vector<vector<int>>(s1, vector<int>(s2, -1)); // Initialize memoization table
        return func(word1, word2, s1 - 1, s2 - 1);
    }
};
