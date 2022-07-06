class Solution {
    
    
bool isSafe(int n, int row, int col, map<int, bool>& rowMap, map<int, bool>& upperDiagonalMap, map<int, bool>& lowerDiagonalMap){
    // check in row
    if(rowMap[row]) return false;
    
    // check in upper diagonal
    if(upperDiagonalMap[(n-1)+(col-row)]) return false;
    
    // check in lower diagonal
    if(lowerDiagonalMap[col+row]) return false;
    
    // no queen attacking, so its safe
    return true;
}

void addSolution(int n, vector<vector<int>>& board, vector<vector<string>>& ans){
    vector<string> temp;
    string str = "";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 1)
                str.push_back('Q');
            else
                str.push_back('.');
        }
        temp.push_back(str);
        str = "";
    }
    ans.push_back(temp);
}

void solve(int col, int n, vector<vector<int>>& board, vector<vector<string>>& ans, map<int, bool>& rowMap, map<int, bool>& upperDiagonalMap, map<int, bool>& lowerDiagonalMap){
    if(col == n){
        addSolution(n, board, ans);
        return;
    }
    
    for(int row=0; row<n; row++){
        if(isSafe(n, row, col, rowMap, upperDiagonalMap, lowerDiagonalMap)){
            board[row][col] = 1;
            
            rowMap[row] = true;
            upperDiagonalMap[(n-1)+(col-row)] = true;
            lowerDiagonalMap[col+row] = true;

            solve(col+1, n, board, ans, rowMap, upperDiagonalMap, lowerDiagonalMap);
            // backtrack
            board[row][col] = 0;
            rowMap[row] = false;
            upperDiagonalMap[(n-1)+(col-row)] = false;
            lowerDiagonalMap[col+row] = false;
        }
    }
}

vector<vector<string>> nQueens(int n){
	vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<string>> ans;   

    map<int, bool> rowMap;
    map<int, bool> upperDiagonalMap;
    map<int, bool> lowerDiagonalMap;
    
    int col = 0;
    solve(col, n, board, ans, rowMap, upperDiagonalMap, lowerDiagonalMap);
	
    return ans;
}

    
public:
    vector<vector<string>> solveNQueens(int n) {
        return nQueens(n);
    }
};