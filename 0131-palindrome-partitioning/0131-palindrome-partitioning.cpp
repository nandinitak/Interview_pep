class Solution {
public:
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

    // Backtracking function to find all palindrome partitions
    void func(vector<vector<string>> &result, vector<string> &ds, string &s, int index) {
        int n = s.length();
        if (index == n) {
            result.push_back(ds);
            return;
        }

        for (int i = index; i < n; i++) {
            if (isPalindrome(s, index, i)) { // Check if substring is a palindrome
                ds.push_back(s.substr(index, i - index + 1));
                func(result, ds, s, i + 1); // Move to the next partition
                ds.pop_back(); 
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> ds; 
        func(result, ds, s, 0);
        return result;
    }
};
