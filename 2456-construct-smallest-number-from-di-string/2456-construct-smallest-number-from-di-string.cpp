class Solution {
public:
    string smallestNumber(string p) {
        int n = p.length();
        vector<int>result;
        for(int i=0;i<=n;i++){
            result.push_back(i+1);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(p[i]=='I' ){
                if(count>1){
                    reverse(result.begin()+i-count,result.begin()+i);
                }
                count=0;
            }
            if(p[i]=='D'){
                swap(result[i],result[i+1]);
                count++;
            }
        }
        if(count>1){
            reverse(result.end()-count-1,result.end()-1);
        }

        string r="";
        for(int i=0;i<=n;i++){
            r+=to_string(result[i]);
        }
        return r;
    }
};