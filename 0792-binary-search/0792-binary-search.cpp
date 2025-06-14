class Solution {
public:
    int search(vector<int>& nums, int target) {
         int n = nums.size();
        int right = n-1;
        int low = 0;
        while(low<=right){
            int mid = (low+right)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(target<nums[mid]){
                right = mid -1;
            }
            else{
                low = mid +1;
            }

        }
        return -1;
    }
};