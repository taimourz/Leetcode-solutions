class Solution {
public:
    void helper(int i, int j, int row, int col, vector<vector<char>> &board){
        // base case
        if(i < 0 || j < 0 || i > row - 1 || j > col - 1) return;

        if(board[i][j] == 'O'){
            board[i][j] = 'P';
            helper(i + 1, j, row, col, board);
            helper(i - 1, j, row, col, board);
            helper(i, j + 1, row, col, board);
            helper(i, j - 1, row, col, board);
        } 
        
        return;
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i == 0 || j == 0 || i == row - 1 || j == col - 1){
                    helper(i, j, row, col, board);
                }
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'P') board[i][j] = 'O';
            }
        }
    }
};