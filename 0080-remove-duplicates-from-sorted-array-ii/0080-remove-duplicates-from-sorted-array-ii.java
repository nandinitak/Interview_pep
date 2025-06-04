class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;

        int i = 1, j = 1;
        int cnt = 1;

        while (j < n) {
            if (nums[j] == nums[j - 1]) {
                cnt++;
            } else {
                cnt = 1;
            }

            if (cnt <= 2) {
                nums[i] = nums[j];
                i++;
            }

            j++;
        }

        return i;
    }
}
