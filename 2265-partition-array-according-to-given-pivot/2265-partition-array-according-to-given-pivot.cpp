class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                s.push(nums[i]);
            }
        }
         for(int i=0;i<n;i++){
            if(nums[i]==pivot){
                s.push(nums[i]);
            }
         }
          for(int i=0;i<n;i++){
            if(nums[i]>pivot){
                s.push(nums[i]);
            }
        }
        for(int i=n-1;i>=0;i--){
            int e= s.top();
            s.pop();
            ans[i]=e;
        }
        return ans;
    }
};