class Solution {
    
    bool isSafe(int x, int y, int index, vector<vector<char>>& board, string& word){
        if((x >= 0 && x < board.size()) && (y >= 0 && y < board[0].size()) && board[x][y] != '-' && board[x][y] == word[index]){
            return true;
        }        
        return false;
    }
    
    
    bool solve(int row, int col, int index, vector<vector<char>>& board, string& word){
        if(index >= word.length() - 1) return true;
        
        char temp = board[row][col];
        board[row][col] = '-';
        
        // move down
        if(isSafe(row+1, col, index+1, board, word)){
            if(solve(row + 1, col, index+1, board, word))
                return true;
        }
        
        // move left
        if(isSafe(row, col-1, index+1, board, word)){
            if(solve(row, col - 1, index+1, board, word))
                return true;
        }
        
        // move right
        if(isSafe(row, col+1, index+1, board, word)){
            if(solve(row, col + 1, index+1, board, word))
                return true;
        }
        
        // move up
        if(isSafe(row-1, col, index+1, board, word)){
            if(solve(row - 1, col, index+1, board, word))
                return true;
        }
        
        board[row][col] = temp;
        
        return false;
    }
    
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == word[0] && solve(i, j, 0, board, word)){
                    return true;
                }
            }
        }
        
        return false;
    }
};