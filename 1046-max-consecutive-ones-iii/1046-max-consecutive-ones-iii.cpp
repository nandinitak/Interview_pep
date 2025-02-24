class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i= 0, count = 0, maxLength = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == 0) {
                count++;
            }

            // Move left pointer if zero count exceeds k
            if (count > k) {
                if (nums[i] == 0) {
                    count--;
                }
                i++;
            }

            maxLength = max(maxLength, j - i+ 1);
        }

        return maxLength;
    }
};
