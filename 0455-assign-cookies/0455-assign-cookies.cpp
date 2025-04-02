class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size() - 1;
        int m = s.size() - 1;
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int count = 0;
        while (n >= 0 && m >= 0) {
            if (s[m] >= g[n]) {
                count++;

                n--;
                m--;
            }
            else
            n--;
        }
        return count;
    }
};