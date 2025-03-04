class Solution {
public:
void dfs(int node,vector<int> &vis,vector<vector<int>> &adj)
{
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isc) {
        int n = isc.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
                if(isc[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        
        }
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
         
            if(!vis[i]){
                ++count;
                dfs(i,vis,adj);
            }
        }
        return count;
        
    }
};