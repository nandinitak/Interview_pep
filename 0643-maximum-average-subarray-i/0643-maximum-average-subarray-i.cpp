class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum=0;
        // int l =0;
        // int e= k-1;
        double av;
        int maxi= INT_MIN;
        if(n==1 && k==1){
            return nums[0];
        }
       for(int i=0; i<k;i++){
        sum+=nums[i];

       }
       maxi=sum;
       for(int i=k;i<n; i++){
        sum+=nums[i]-nums[i-k];
        maxi=max(maxi,sum);
       }
       av=(double)maxi/k;
       return av;
    }
};