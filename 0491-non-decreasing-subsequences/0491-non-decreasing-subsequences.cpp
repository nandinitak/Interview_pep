class Solution {
public:
    void ans(vector<vector<int>>& result, int j, vector<int> ds, int index, vector<int>& nums) {
        if (ds.size() >= 2) {
            result.push_back(ds);
        }

        for (int i = j; i < nums.size(); ++i) {
            if (ds.empty() || nums[i] >= ds.back()) {
                ds.push_back(nums[i]);
                ans(result, i + 1, ds, index, nums);
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        map<vector<int>,int> m;
        vector<int> ds;
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> temp;
            temp.push_back(nums[i]);
            ans(result, i + 1, temp, i, nums);
        }
        for(int i=0;i<result.size();i++){
            m[result[i]]++;
        }
        result={{}};
        result.pop_back();
        for(auto p:m){
            result.push_back(p.first);
        }
        return result;
    }
};
