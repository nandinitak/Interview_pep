class Solution {
public:
    int maxi = INT_MAX;

    string odd(int n, string s) {
        string a = "";
        for (int i = 0; i < n; i++) {
            int j = i - 1;
            int k = i + 1;
            while (j >= 0 && k < n && s[j] == s[k]) { 
                j--;
                k++;
            }
            if (a.size() < k - j - 1) {
                a = s.substr(j + 1, k - j - 1);
            }
        }
        return a;
    }

    // string even(int n, string s) {
    //     string b = "";
    //     for (int i = 0; i < n - 1; i++) {
    //         int j = i;
    //         int k = i + 1;
    //         if (s[j] == s[k]) {
    //             while (j >= 0 && k < n && s[j] == s[k]) {
    //                 j--;
    //                 k++;
    //             }
    //             if (b.size() < k - j - 1) {
    //                 b = s.substr(j + 1, k - j - 1);
    //             }
    //         }
    //     }
    //     return b;
    // }

string even(int n, string s) {
    string b = "";
    for (int i = 0; i < n - 1; i++) {  
        int left = i, right = i;

        if (s[i] == s[i + 1]) {  
            right++;
        }

        int j = left - 1, k = right + 1;
        while (j >= 0 && k < n && s[j] == s[k]) { 
            left = j;
            right = k;
            j--;
            k++;
        }

        if (b.size() < right - left + 1) {
            b = s.substr(left, right - left + 1);  
        }
    }
    return b;
}


    string longestPalindrome(string s) { 
        int n = s.size();
        string a =  odd(n,s);
        string b = even(n,s);
        if(a.length()>b.length()){
            return a;
        }else{
            return b;
        }
       
     }
};