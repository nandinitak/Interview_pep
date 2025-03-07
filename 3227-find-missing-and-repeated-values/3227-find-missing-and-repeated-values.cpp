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
        
//     }
//     class Solution {
// public:
//     vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
//         int n = grid.size();
//         vector<int> freq(n * n + 1, 0); 

//         int repeated = -1, missing = -1;

    
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 freq[grid[i][j]]++;
//             }
//         }
//         for (int i = 1; i <= n * n; i++) {
//             if (freq[i] == 2) repeated = i;
//             if (freq[i] == 0) missing = i;
//         }

//         return {repeated, missing};
//     }
// };

};