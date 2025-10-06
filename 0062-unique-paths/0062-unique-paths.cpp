class Solution {
public:
    bool check_bounds(int row, int col, int i, int j){
        if( i < 0 || j < 0 || i >= row || j >= col) return true;
        return false;
    }
    int helper(int row, int col, int i, int j, vector<vector<int>> &dp){
        if(check_bounds(row, col, i, j)) return 0;
        if(i == row - 1 && j == col - 1) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        if(!check_bounds(row, col, i, j)){
            dp[i][j] = helper(row, col, i+1, j, dp) + helper(row, col, i, j+1, dp);
        }
        return dp[i][j];

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m, n, 0, 0, dp);
       
    }
};