class Solution {
public:
    bool bfs(int j,vector<int> &vis ,vector<vector<int>>& adj,vector<int>&check){
        int V = adj.size();
        queue<int> q;
        // for(int i=j;i<V;i++){
        //     for(auto it: adj[i]){
        //         if(it){
        //             q.push(i);
        //             vis[i]=0;
        //             break;
        //         }
        //     }
        //     if(q.size()>0) break;
        // }
        q.push(j);
        vis[j]=0;
        check[j]=1;
        while(!q.empty()){
            int node = q.front();;
            int color = vis[node];
            q.pop();
            for(auto it:adj[node]){
                if( vis[it]==color){
                    return false;
                }
                else if(vis[it]==-1){
                    if(color==1){
                        q.push({it});
                        vis[it]=0;  
                        check[it]=1;  
                    }
                    else if(color==0){
                        q.push({it});
                        vis[it]=1;
                        check[it]=1;
                    }
                    
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int>vis(V,-1);
        vector<int>check(V,0);
        // vector<vector<int>>adj(V);
        // for(int i=0;i<edges.size();i++){
        //     adj[edges[i][0]].push_back(edges[i][1]);
        //     adj[edges[i][1]].push_back(edges[i][0]);
        // }
        // queue<int> q;
        // for(int i=0;i<V;i++){
        //     for(auto it: adj[i]){
        //         if(it){
        //             q.push(i);
        //             vis[i]=0;
        //             break;
        //         }
        //     }
        //     if(q.size()>0) break;
        // }
        // q.push(0);
        // vis[0]=0;
        // while(!q.empty()){
        //     int node = q.front();;
        //     int color = vis[node];
        //     q.pop();
        //     for(auto it:adj[node]){
        //         if( vis[it]==color){
        //             return false;
        //         }
        //         else if(vis[it]==-1){
        //             if(color==1){
        //                 q.push({it});
        //                 vis[it]=0;    
        //             }
        //             else if(color==0){
        //                 q.push({it});
        //                 vis[it]=1;
        //             }
                    
        //         }
        //     }
        // }
        for(int i=0;i<V;i++){
            if(!check[i]){
                if(bfs(i,vis,adj,check)==false) return false;
            }
        }
        return true;
    }
};