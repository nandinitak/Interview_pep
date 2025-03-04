class Solution {
public:
    bool check(int i,vector<int>&arr,int n,int sum , int target){
        if(i==n){
            return target==sum;
        }
        sum+=arr[i];
        if(check(i+1,arr,n,sum,target)==true){
            return true;
        }
        sum-=arr[i];
        if(check(i+1,arr,n,sum,target)==true){
            return true;
        }
        return false;
    }
    bool checkPowersOfThree(int n) {
        int k = 0;
        int power = 1; 
        while (power * 3 <= n) {
            power *= 3;
            k++;
        }
        vector<int>arr;
        for(int i=0;i<=k;i++){
            arr.push_back(pow(3,i));
        }
        return check(0,arr,arr.size(),0,n);
    }
};