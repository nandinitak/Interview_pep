class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
         long long currentMax=0;
         long long maxDiff=0;
         long long maxproduct=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            maxproduct = max(maxproduct,maxDiff*nums[i]);
           maxDiff= max(maxDiff,currentMax-nums[i]);
           if(nums[i]>currentMax) currentMax=nums[i];
          
            
        }
        return maxproduct;
    }
};