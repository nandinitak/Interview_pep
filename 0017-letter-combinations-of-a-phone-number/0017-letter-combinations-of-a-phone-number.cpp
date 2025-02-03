class Solution {
public:


    void func(unordered_map <int,string> mp,int n,vector<string> &result,string digits,int index,string ds){
        if(index>=n){
            result.push_back(ds);
            return;
        }
        int a = digits[index] - '0';
        string s=mp[a];
        for(int i=0; i<s.length();i++){
            ds.push_back(s[i]);
            func(mp,n,result,digits,index+1,ds);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map <int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";

    
    int n = digits.size();
     vector<string> result;
        if(n==0){
            return result;
        }
     string ds;
    func(mp,n,result,digits,0,ds);
    return result;
} 
};