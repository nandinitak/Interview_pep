#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxi = 0;
        int count = 0;
        unordered_map<char, int> mpp;
        
        int j = 0; 
        for (int i = 0; i < n; i++) {
            mpp[s[i]]++; 

            
           
            while (mpp[s[i]] > 1) {
                mpp[s[j]]--;
                j++;
                count--;
            }
         count++;
            maxi = max(maxi, count); 
        }

        return maxi;
    }
};
