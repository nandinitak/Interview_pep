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
            sum+=nums[index];
            ds.push_back(nums[index]);
            func(nums,target,result,n,index+1,ds);
            sum-=nums[index];
            ds.pop_back();
            for(int i=index; i<n-1;i++){
                if(nums[index]==nums[i+1]){
                    index++;
                }
            }
            func(nums,target,result,n,index+1,ds);
            
       
}
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ds;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        func(nums,target,result,n,0,ds);
        // for(auto i: result){
            
        // }
        return result;
    }
};