class Solution {
public:
    bool dfs(int i,vector<int>& vis,vector<int>& path, vector<vector<int>>&adj,vector<int>&check ){
        vis[i]=1;
        path[i]=1;
        check[i]=0;
        for(auto it: adj[i]){
            if(!vis[it]){
                 if(dfs(it,vis,path,adj,check)==true) return true;
            }
            else if (path[it]){
               return true;
            }
    
        }
        check[i]=1;
        path[i]=0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int>vis(V,0);
        vector<int>path(V,0);
        vector<int>check(V,0);
        vector<int>safe;
        // vector<vector<int>>adj(V);
        // for(int i=0;i<edges.size();i++){
        //     adj[edges[i][0]].push_back(edges[i][1]);
        //     // adj[edges[i][1]].push_back(edges[i][0]);
        // }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,path,adj,check));
            }
        }
        for(int i=0;i<V;i++){
            if(check[i]==1) safe.push_back(i);
        }
        return safe;
    }
};