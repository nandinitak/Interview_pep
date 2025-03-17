class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>pre;
        vector<int>suf(nums.size());
        int pro=1;
        for(auto i :nums){
            pre.push_back(pro);
            pro*=i;
        }
        pro = 1;
        // for(int i=nums.size()-1;i>=0;i--){
        //     suf[i]=pro;
        //     pro*=nums[i];
        // }
        for(int i=nums.size()-1;i>=0;i--){
            pre[i]=pre[i]*pro;
            pro*=nums[i];
        }
        return pre;

    }
};