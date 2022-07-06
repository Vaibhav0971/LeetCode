class Solution {
    
bool isSafe(char val, int row, int col, vector<vector<char>>& board){
    for(int i=0; i<board[0].size(); i++){
        // check row
        if(board[row][i] == val) return false;
        // check col
        if(board[i][col] == val) return false;
        // check submatrix
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val) return false;
    }
    
    // value is not repeated, so its safe
    return true;
}
    
bool solve(vector<vector<char>>& board){
    int n = board[0].size();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == '.'){
                for(int val=1; val<=9; val++){
                    if(isSafe('0' + val, i, j, board)){
                        board[i][j] = '0' + val;
                        bool isFurtherSolutionPossibile = solve(board);
                        if(isFurtherSolutionPossibile) return true;
                        else board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}    
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);        
    }
};