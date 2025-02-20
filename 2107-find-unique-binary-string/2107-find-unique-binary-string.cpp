class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string s="";
        for(int i=0;i<n;i++){
            if(nums[i][i]=='1'){
                s+='0';
            }else{
                s+='1';
            }
        }
        return s;
    }
};