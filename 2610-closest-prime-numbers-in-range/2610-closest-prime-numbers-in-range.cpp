#include <iostream>
#include <map>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false; 
        for (int i = 2; i * i <= n; i++) { 
            if (n % i == 0) 
                return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> nums;
        int mindiff=INT_MAX;
        vector<int> pair(2);
        pair[0]=-1;
        pair[1]=-1;


        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                nums.push_back(i);
            }
        }

        for( int i=1;i<nums.size(); i++){
           int diff= nums[i]-nums[i-1];
           if(diff<mindiff){
            mindiff=diff;
            pair[0]=nums[i-1];
            pair[1]=nums[i];
           }
        }


      return pair;
    }
};
