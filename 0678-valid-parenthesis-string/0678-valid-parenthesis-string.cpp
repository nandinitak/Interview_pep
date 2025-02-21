class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0; // low tracks minimum open, high tracks maximum open

        for (char c : s) {
            if (c == '(') {
                low++, high++;
            } else if (c == ')') {
                low--, high--;
            } else { // c == '*'
                low--, high++; // '*' can be '(' or ')'
            }

            if (high < 0) return false; // More closing brackets than possible

            if (low < 0) low = 0; // low cannot go negative (it can be adjusted by *)
        }

        return low == 0; // If `low` reaches 0, valid string
    }
};
