class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        if(n==1 && m==1 && A[0][0]==0) return 1;
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        if(A[0][0]!=1) q.push({1,{0,0}});
        int delR[] = {-1,-1,0,1,1,1,0,-1};
        int delC[] = {0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            auto it = q.front(); q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i=0;i<8;i++){
                int newR = r+delR[i];
                int newC = c+delC[i];
                if(newR>=0 && newR<n && newC>=0 && newC<m
                   && A[newR][newC]==0 && dis+1<dist[newR][newC]){
                       dist[newR][newC] = dis+1;
                       if(newR==n-1 && newC==m-1) return dis+1;
                       q.push({dis+1,{newR,newC}});
                   }
            }
        }
        return -1;
    }
};