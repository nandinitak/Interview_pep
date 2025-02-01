class Solution {
public:
void func(int n, int k,vector<int> nums,vector<int> &ds,vector<vector<int>> &result,int ind){
    int sum = accumulate(ds.begin(),ds.end(),0);
    // if(ind==n) return;
    if(sum>n)return;
    if(ds.size()==k){
        if(sum==n){
        result.push_back(ds);
       
        }
         return;
    }
    for(int i=ind;i<nums.size();i++){
    ds.push_back(nums[i]);
    func(n,k,nums,ds,result,i+1);
    ds.pop_back();
    // func(n,k,nums,ds,result,ind+1);
    }
} 


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> nums;
        for(int i=1;i<=9;i++){
            nums.push_back(i);
        }
        vector<int>ds;
        func(n,k,nums,ds,result,0);
        return result;
    }
    
};