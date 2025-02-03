class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        string s = to_string(x);
        int n =s.length();
        int l=0;
        int e = n-1;
        while(l<=e){
            if(s[l++]!=s[e--]){
                return false;

            }
           
        }
        return true;

    }
};