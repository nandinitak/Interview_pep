class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum=0;
        int l =0;
        int e= k-1;
        double av;
        int maxi= INT_MIN;
        if(n==1 && k==1){
            return nums[0];
        }
       for(int i=0; i<n;i++){
        sum+=nums[i];
        if(i==e){
            maxi=max(maxi,sum);
            sum-=nums[l];
            l++;
            e++;
        }
       }
       av=(double)maxi/k;
       return av;
    }
};