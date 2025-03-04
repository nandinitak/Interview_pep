class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                nums.push_back(i);
            }
        }
        if(nums.size()<k) return -1;
        sort(nums.begin(),nums.end());
        return nums[k-1];
    } 
};