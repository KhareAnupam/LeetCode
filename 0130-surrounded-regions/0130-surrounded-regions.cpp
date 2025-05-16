class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& mat, vector<vector<int>> &vis ){
        int n= mat.size();
        int m= mat[0].size();
        if(j+1<m && mat[i][j+1]=='O' && !vis[i][j+1]){
            vis[i][j+1]=1;
            dfs(i,j+1,mat,vis);
        }
        if(i+1<n && mat[i+1][j]=='O' && !vis[i+1][j]){
            vis[i+1][j]=1;
            dfs(i+1,j,mat,vis);
        }
        if(j-1>=0 && mat[i][j-1]=='O' && !vis[i][j-1]){
            vis[i][j-1]=1;
            dfs(i,j-1,mat,vis);
        }
        if(i-1>=0 && mat[i-1][j]=='O' && !vis[i-1][j]){
            vis[i-1][j]=1;
            dfs(i-1,j,mat,vis);
        }
    }
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0] && mat[i][0]=='O'){
                vis[i][0]=1;
                dfs(i,0,mat,vis);
            }
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                vis[i][m-1]=1;
                dfs(i,m-1,mat,vis);
            }
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j] && mat[0][j]=='O'){
                vis[0][j]=1;
                dfs(0,j,mat,vis);
            }
            if(!vis[n-1][j] && mat[n-1][j]=='O'){
                vis[n-1][j]=1;
                dfs(n-1,j,mat,vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    mat[i][j]='X';
                }
            }
        }
    }
};