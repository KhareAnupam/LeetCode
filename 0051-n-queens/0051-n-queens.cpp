class Solution {
public:
    bool isValid(int row, int col, vector<string>& board, int n){
        int nrow=row;
        int ncol=col;
        while(ncol>=0){
            if(board[nrow][ncol]=='Q') return false;
            ncol--;
        }
        nrow=row;
        ncol=col;
        while(nrow<n && ncol >=0){
            if(board[nrow][ncol]=='Q') return false;
            ncol--;
            nrow++;
        }
        nrow=row;
        ncol=col;
        while(nrow>=0 && ncol >=0){
            if(board[nrow][ncol]=='Q') return false;
            ncol--;
            nrow--;
        }
        return true;
    }
    void helper(int col,int n,vector<string> &board, vector<vector<string>>&ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isValid(row,col,board,n)==true){
                board[row][col]= 'Q';
                helper(col+1,n,board,ans);
                board[row][col]= '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if(n==0) return ans;
        string s(n,('.'));
        vector<string>board;
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        helper(0,n,board,ans);
        return ans;
    }
};