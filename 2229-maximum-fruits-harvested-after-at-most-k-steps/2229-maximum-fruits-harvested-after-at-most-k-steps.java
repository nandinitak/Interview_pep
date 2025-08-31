class Solution {
    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        int maxFruitsCollected = 0;
        int maxIndex = fruits[fruits.length-1][0];
        int[] maxFruitsCollectAtPos = new int[Math.max(maxIndex, startPos)+1];
        int startPosInFruits = 0;
        int startPosInFruitsNext = 0;
        for (int i = 0; i < fruits.length; i++) {
            if(startPos >= fruits[i][0]) {
                startPosInFruits = i;
                startPosInFruitsNext = i + 1;
            } else {
                break;
            }
        }
        for(int i = startPosInFruitsNext, j = startPos+1, maxFruitCollect = 0; j <= maxIndex && j <= startPos + k; j++) {
            if(fruits[i][0] == j) {
                maxFruitCollect += fruits[i][1];
                i++;
            }
            maxFruitsCollectAtPos[j] = maxFruitCollect;
        }
        for(int i = startPosInFruits, j = startPos, maxFruitCollect = 0; j >= 0 && i >= 0; j--) {
            if(fruits[i][0] == j) {
                maxFruitCollect += fruits[i][1];
                i--;
            }
            maxFruitsCollectAtPos[j] = maxFruitCollect;
        }
        for(int i = 0; i < fruits.length; i++) {
            int fruitCollect = 0;
            int left = Math.min(fruits[i][0], startPos);
            if(left >= startPos - k && left <= startPos + k) {
                int right1 = startPos + (k - (startPos - left) * 2);
                int right2 = startPos + (k - (startPos - left)) / 2;
                int right = Math.max(right1, right2);
                right = Math.min(right, maxIndex);
                if(left <= startPos)
                    fruitCollect = maxFruitsCollectAtPos[left];
                if(right > startPos) {
                    fruitCollect += maxFruitsCollectAtPos[right];
                }
                maxFruitsCollected = Math.max(maxFruitsCollected, fruitCollect);
            }
        }

        return maxFruitsCollected;
    }
}