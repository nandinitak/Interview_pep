#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string &curr) {
        int count = 0;
        for (char &ch : curr) {
            if (ch == '(') {
                count++;
            } else {
                count--;
            }
            if (count < 0) return false; // Prevents invalid sequences
        }
        return count == 0;
    }

    void solve(string &curr, int n, vector<string> &result) {
        if (curr.length() == 2 * n) {
            if (isValid(curr)) {
                result.push_back(curr);
            }
            return;
        }

        curr.push_back('(');
        solve(curr, n, result);
        curr.pop_back();

        curr.push_back(')');
        solve(curr, n, result);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        vector<string> result;
        solve(curr, n, result);
        return result;
    }
};
