class Solution {
public:
    bool isValid(int i, int j, int row, int col){
        if(i < 0 || j < 0 || i >= row || j >= col) return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int row = mat.size();
       int col = mat[0].size();
       queue<pair<int, int>> q;
       vector<vector<int>> ans(row, vector<int>(col, -1));
       for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(mat[i][j] == 0){
                q.push({i, j});
                ans[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int i = node.first;
            int j = node.second;

            if(isValid(i + 1, j, row, col) && ans[i+1][j] == -1){
                q.push({i+1, j});
                ans[i+1][j] = ans[i][j] + 1;
            }
            if(isValid(i-1, j, row, col) && ans[i-1][j] == -1){
                q.push({i-1, j});
                ans[i-1][j] = ans[i][j] + 1;
            }

            if(isValid(i, j+1, row, col) && ans[i][j+1] == -1){
                q.push({i, j+1});
                ans[i][j+1] = ans[i][j] + 1;

            }
            if(isValid(i, j-1, row, col) && ans[i][j-1] == -1){
                q.push({i, j-1});
                ans[i][j-1] = ans[i][j] + 1;
            }
        }
        return ans;
    }
};


/*
need a 2d ans matrix with -1 initialized
the enteries where we have 0, will be flipped to 0
We will use these 0 for BFS. bfs will set the distance to its neighbours
ofcourse, -1 also indicates that we have not visited that area.
in bfs we do the standard, adding neighbour after processing it.
impt thing, the distance added would be sum of current node + 1
return ans





*/
