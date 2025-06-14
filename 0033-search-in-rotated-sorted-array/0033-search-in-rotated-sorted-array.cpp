class Solution {
public:
    int search(vector<int>& nums, int target) {
         int n = nums.size();
        int high=n-1;
        int low=0;
        while(low<=high){
            int mid=(low+high)/2;

            if(target==nums[mid]) return mid;

            if(nums[low]<=nums[mid] ){
            if(nums[low]<=target && nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            }
            if(nums[mid]<nums[high]){
            if(nums[high]>=target&&nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
            }
          
        }

          return -1;
    }
};