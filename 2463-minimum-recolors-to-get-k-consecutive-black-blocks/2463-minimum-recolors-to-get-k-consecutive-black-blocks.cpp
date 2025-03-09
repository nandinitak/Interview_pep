class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int minWhite = k;
        int whiteCount = 0;

        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                whiteCount++;
            }
        }

        minWhite = whiteCount;

        for (int i = k; i < n; i++) {
            if (blocks[i - k] == 'W') {
                whiteCount--;
            }
            if (blocks[i] == 'W') {
                whiteCount++;
            }
            minWhite = min(minWhite, whiteCount);
        }

        return minWhite;
    }
};
