class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        int maxreach=0;
        int currentend=0;
        for(int i=0;i<n-1;i++){
            maxreach=max(maxreach,i+nums[i]);
            if(i==currentend){
                count++;
                currentend=maxreach;

            }
        }
        return  count;
    }
};