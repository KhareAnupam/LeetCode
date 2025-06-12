class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int delR[] = {-1,0,1,0};
        int delC[] = {0,1,0,-1};
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dif = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r==n-1 && c==m-1) return dist[r][c];
            for(int i=0;i<4;i++){
                int newR = r+delR[i];
                int newC = c+delC[i];
                if(newR>=0 && newR<n && newC>=0 && newC<m){
                    int newDif = abs(heights[newR][newC] - heights[r][c]);
                    if(max(newDif,dif)<dist[newR][newC]){
                        dist[newR][newC] = max(newDif,dif);
                        pq.push({max(newDif,dif),{newR,newC}});
                    }
                }
            }
        }
        return 0;
    }
};