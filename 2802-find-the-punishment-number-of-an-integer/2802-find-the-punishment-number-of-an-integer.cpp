class Solution {
public:
    bool isValidPartition(int num, int square) {
        return checkPartition(square, num, 0);
    }

    bool checkPartition(int sq, int target, int currentSum) {
        if (sq == 0) return currentSum == target;
        
        int part = 0, mul = 1;
        while (sq > 0) {
            part = (sq % 10) * mul + part;
            sq /= 10;
            mul *= 10;
            if (checkPartition(sq, target, currentSum + part)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            if (isValidPartition(i, sq)) {
                sum += sq;
            }
        }
        return sum;
    }
};
