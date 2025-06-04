class Solution {
public:
    int majorityElement(vector<int>& nums) {
       
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        sort(nums.begin(), nums.end());
        int i=1; int j=1,ans;
        int cnt=1,  maxi= 1;
        while(i<n){
            if(nums[i]==nums[i-1]){
                cnt++;
                if(cnt>n/2){
                    ans=nums[i];
                    maxi=max(maxi,cnt);
                }
            }else{
                 cnt=1;
                 
            }

            i++;
        }
        return  ans;
    }
};