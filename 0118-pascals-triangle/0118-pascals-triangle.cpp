class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);
        // for(int i=0;i<numRows;i++){
        //     vector<int> a(i+1);
        //     v.push_back(a);
        //     for(int j=0;j<=i;j++){
        //         if(i==j || j==0) v[i][j] =1;
        //         else v[i][j] = v[i-1][j] + v[i-1][j-1];
        //     }
        // }
        for(int i=0;i<numRows;i++){
            int ans=1;
            v[i].push_back(ans);
            for(int j=1;j<=i;j++){
                ans*= (i+1-j);
                ans/=j;
                v[i].push_back(ans);

            }
        }


        return v;

    }
};