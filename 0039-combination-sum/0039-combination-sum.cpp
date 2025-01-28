class Solution {
public:
void func(vector<int>&nums,int target, vector<vector<int>> &result,int n,int index,vector<int> &ds){
  
            int sum = accumulate(ds.begin(),ds.end(),0);
            if(sum>target){
                return;
            }
            if(sum==target){
                result.push_back(ds);
                return;
            }
            if(index==n){
                return;
            }
            ds.push_back(nums[index]);
            func(nums,target,result,n,index,ds);
            ds.pop_back();
            func(nums,target,result,n,index+1,ds);

       
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ds;
        vector<vector<int>> result;
        func(nums,target,result,n,0,ds);
        return result;
    }
};