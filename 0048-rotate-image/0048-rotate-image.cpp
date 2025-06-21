class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        int q,r;
        for(int i=0;i<n;i++){
            q=0;
            r=n-1;
            while(q<r){
                swap(matrix[i][q],matrix[i][r]);
                q++;
                r--;
            }
        }
    }
};