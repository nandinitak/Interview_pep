class Solution {
public:
    bool checkPowersOfThree(int n) {
        int sum=0;

        while(n>0){
            if(n%3==2) return false;
            n/=3;
        }
        return true;
        
    }
};