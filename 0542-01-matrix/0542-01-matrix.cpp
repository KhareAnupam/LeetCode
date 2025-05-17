class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0)) , dist(n,vector<int>(m,0));
        
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            pair<pair<int,int>,int> cur = q.front();
            q.pop();
            int i = cur.first.first;
            int j = cur.first.second;
            int distance = cur.second;
            dist[i][j] = distance;
            if(j+1<m && !vis[i][j+1]){
                q.push({{i,j+1},distance+1});
                vis[i][j+1] =1;
            }
            if(i+1<n && !vis[i+1][j]){
                q.push({{i+1,j},distance+1});
                vis[i+1][j] = 1;
            }
            if(j-1>=0 && !vis[i][j-1]){
                q.push({{i,j-1},distance+1});
                vis[i][j-1]=1;
            }
            if(i-1>=0 && !vis[i-1][j]){
                q.push({{i-1,j},distance+1});
                vis[i-1][j]=1;
            }
        }
        
        return dist;
    }
};