class Solution {
public:
    string smallestNumber(string pattern) {
        string result="";
        stack<int> s;
        int n = pattern.length();
        for(int i=0;i<=n;i++){
            s.push(i+1);
            if(i==n|| pattern[i]=='I'){
                while(!s.empty()){
                    result+=to_string(s.top());
                    s.pop();
                }
            }
        }
        return result;
    }
};