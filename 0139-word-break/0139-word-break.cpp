class Solution {
public:
   bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> mp(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
                string a=s.substr(j,i-j);
                if(mp.find(a)!=mp.end() && dp[j]){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
        
    }

};