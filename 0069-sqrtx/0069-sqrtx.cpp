class Solution {
public:
    int mySqrt(int n) {
        long long low=1;
         long long high=n;
         long long ans;
         if(n==0 || n==1) return n;
         while(low<=high){
             long long mid= (low+high)/2;
             long long dec= n/mid;
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