class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long m = grid.size();
        long long n = m*m;
        long long s2n = (n * (n+1) * (2*n+1))/6;
        long long sn = (n * (n+1))/2;
        // long long s3n = calc*clac;
        long long s2=0,s=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                s2 += (long long)grid[i][j] * (long long)grid[i][j];
                s += (long long)grid[i][j];
            }
        }
        long long val1 = s-sn;
        long long calc = s2n-s2;
        long long val2 = calc/val1;
        long long first = (val1+val2)/2;
        long long second = first - val1;
        return {(int)abs(second),(int)abs(first)};
    }
};