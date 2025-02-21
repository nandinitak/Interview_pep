class Solution {
public:
    bool isPalindrome(string s) {
    string s1="";
    int n = s.length();

    for (char c : s) {
        if (isalnum(c)) {
            s1 += tolower(c);
        }
    }
    if(equal(s1.begin(), s1.end(), s1.rbegin())){
        return true;
    }else{
        return false;
    }
    }
};