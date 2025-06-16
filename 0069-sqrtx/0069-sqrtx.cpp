class Solution {
public:
    int mySqrt(int n) {
        int low=1;
         int high=n;
         int ans;
         if(n==0 || n==1) return n;
         while(low<=high){
             int mid=low+(high-low)/2;
             int dec= n/mid;
             if(dec==mid){
                 return dec;
             }
             else if(dec<mid){
                 high=mid-1;
                 
             }
             else{
                 ans=mid;
                 low=mid+1;
             }
         }
         return ans;
    }
    
};