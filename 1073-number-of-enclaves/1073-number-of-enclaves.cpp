class Solution {
public:
    void dfs(int i, int j,vector<vector<int>> &mat, vector<vector<int>> &vis){
            vis[i][j]=1;
            int n= mat.size();
            int m= mat[0].size();
            if(j+1<m && mat[i][j+1]==1 && !vis[i][j+1]){
                // vis[i][j+1]=1;
                dfs(i,j+1,mat,vis);
            }
            if(i+1<n && mat[i+1][j]==1 && !vis[i+1][j]){
                // vis[i+1][j]=1;
                dfs(i+1,j,mat,vis);
            }
            if(j-1>=0 && mat[i][j-1]==1 && !vis[i][j-1]){
                // vis[i][j-1]=1;
                dfs(i,j-1,mat,vis);
            }
            if(i-1>=0 && mat[i-1][j]==1 && !vis[i-1][j]){
                // vis[i-1][j]=1;
                dfs(i-1,j,mat,vis);
            }
        }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,grid,vis);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,grid,vis);
            }
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,grid,vis);
            }
            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,grid,vis);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1) count++;
            }
        }
        return count;
    }
};