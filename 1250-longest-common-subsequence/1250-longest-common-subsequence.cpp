class Solution {
public:
    int func(int i, int j, string &s, string&t,vector<vector<int>> &dp){
        // if(n==0 || m==0) return 0;
        if(i==0 || j==0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i-1]==t[j-1])
       return dp[i][j]= 1+func(i-1,j-1,s,t,dp);

        return dp[i][j] =max(func(i-1,j,s,t,dp),func(i,j-1,s,t,dp));
        
    }
    int longestCommonSubsequence(string s, string t) {
        int n= s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return func(n,m,s,t,dp);

    }
};