class Solution {
public:
    void generateHappyStrings(int n, string s, vector<string> &result) {
        if (s.length() == n) {
            result.push_back(s);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (s.empty() || s.back() != ch) {
                generateHappyStrings(n, s + ch, result);
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> result;
        generateHappyStrings(n, "", result);

        if (k > result.size()) {
            return "";
        }
        return result[k - 1];
    }
};

