class Solution {
public:
    bool check_bounds(int i, int j, int row, int col){
        if(i < 0 || j < 0 || i >= row || j >= col) return false;
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        queue<tuple<int, int, int>> q;
        int freshCount = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 2) q.push({i,j,0});
                else if(grid[i][j] == 1) freshCount++;
            }
        }
        int maxTime = 0;
        while(!q.empty()){
            auto [i, j, time] = q.front();
            q.pop();
            maxTime = max(maxTime, time);
            if(check_bounds(i+1, j, r, c) && grid[i+1][j] == 1 ){
                grid[i+1][j] = 2;
                q.push({i+1, j, time+1});
                freshCount--;
            }
            if(check_bounds(i-1, j, r, c) && grid[i-1][j] == 1 ){
                grid[i-1][j] = 2;
                q.push({i-1, j, time + 1});
                freshCount--;
            }
            if(check_bounds(i, j+1, r, c) && grid[i][j+1] == 1 ){
                grid[i][j+1] = 2;
                q.push({i, j+1, time + 1});
                freshCount--;
            }
            if(check_bounds(i, j-1, r, c) && grid[i][j-1] == 1 ){
                grid[i][j-1] = 2;
                q.push({i, j-1, time + 1});
                freshCount--;
            }
            
        }

        return freshCount == 0 ? maxTime : -1;

    }
};