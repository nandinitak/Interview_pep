class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        unordered_map<string,int> mpp;
        vector<string> ans;
        for(int i=0;i<n;i++){
             string str=s.substr(i,10);
             mpp[str]++;
        }
       for(auto it: mpp){
        if(it.second>1){
            ans.push_back(it.first);
        }
       }
        return ans;

    }
};