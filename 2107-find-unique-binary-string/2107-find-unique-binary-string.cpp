class Solution {
public:
    void f(int n, string curr, vector<string> &ans) {
        if (curr.size() > n) return;
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        f(n, curr + '0', ans);
        f(n, curr + '1', ans);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        int s = nums[0].length();
        unordered_map<string, int> mpp;
        
        // Fix: Correct insertion into unordered_map
        for (auto &str : nums) {
            mpp[str]++;
        }

        vector<string> ans;
        string curr;
        f(s, curr, ans);  // Fix: Use 's' instead of 'n' to generate correct length strings

        // Find a missing binary string
        for (auto &str : ans) {
            if (mpp.find(str) == mpp.end()) {
                return str;  // Return the first unique string found
            }
        }

        return ""; // Just in case, though the function should always find a unique string
    }
};
