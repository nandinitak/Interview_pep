class Solution {
public:
const int m=1e9+7;
    int countHousePlacements(int n) {
        vector<long long> dp(n+1);
        dp[0]=1;
        dp[1]=2;
        for(int i=2; i<=n; i++){
                dp[i]=(dp[i-1]%m+dp[i-2]%m)%m;
        }
        return (dp[n]%m*dp[n]%m)%m;
    }
};