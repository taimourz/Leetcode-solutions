class Solution {
public:

    void printGrid(const vector<vector<char>>& grid) {
        for (const auto& row : grid) {
            for (char cell : row)
                cout << cell << " ";
            cout << endl;
        }
    }
    int total = 0;
    void helper(int i, int j, int row, int col, vector<vector<char>>& grid){
        if(i<0 || j < 0 || i >= row || j >= col) return;

        if(grid[i][j] == '1'){
            grid[i][j] = 'x';
            helper(i+1, j, row, col, grid);
            helper(i-1, j, row, col, grid);
            helper(i, j+1, row, col, grid);
            helper(i, j-1, row, col, grid);
        }
        // cout<< "Done with iterations : "<<endl;
        // printGrid(grid);        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    helper(i, j, row, col, grid);
                    total += 1;
                }
            }
        }
        return total;

    }
};