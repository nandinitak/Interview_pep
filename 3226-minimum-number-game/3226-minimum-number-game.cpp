class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        while(i<n){
            swap(nums[i],nums[i+1]);
            i+=2;
            // j++;
        }
        return nums;
    }
};