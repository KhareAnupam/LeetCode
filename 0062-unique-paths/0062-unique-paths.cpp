class Solution {
public:
    int f(int i,int j,vector<vector<int>>& dp){
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=0,right=0;
        if(j-1>=0) left += f(i,j-1,dp);
        if(i-1>=0) right += f(i-1,j,dp);
        return dp[i][j] =left+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp);
    }
};