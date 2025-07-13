class Solution {
public:
    bool isValid(int i,int j, int num, vector<vector<char>>& board,int n){
        for(int point=0;point<n;point++){
            if(board[i][point]==num) return false;
            if(board[point][j]==num) return false;
            int row; int col;
            row = (3 * (i/3)) + point/3;
            col = (3* (j/3)) + point%3;
            if(board[row][col]==num) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n= board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==('.')){
                    for(char num='1';num<='9';num++){
                        if(isValid(i,j,num,board,n)){
                            board[i][j]=num;
                            if(solve(board)==true) return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }
};