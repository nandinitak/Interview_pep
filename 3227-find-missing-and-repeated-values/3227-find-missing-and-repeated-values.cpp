class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> mpp;
        vector<int> result;
        int n = grid.size();
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                mpp[grid[i][j]]++;
            }
        }

        for(auto it:mpp){
            if(it.second>1){
                result.push_back(it.first);
            }
            
        }
        for(int i=1;i<=n*n;i++){
            if(mpp.count(i)){
                continue;
            }else{
                result.push_back(i);
            }
        }
        return result;
        
    }
};