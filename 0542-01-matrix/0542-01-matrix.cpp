class Solution {
public:
    int isValid(int i, int j, int row, int col){
        if(i < 0 || j < 0 || i >= row || j >= col) return false;
        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> ans(row, vector<int>(col, -1));
        queue<pair<int, int>> q;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i,j});
                } 
            }
        }
        while(!q.empty()){
            auto coordinates = q.front();
            q.pop();
            int i = coordinates.first;
            int j = coordinates.second;
            if(isValid(i+1, j, row, col) && ans[i+1][j] == -1){
                ans[i+1][j] = ans[i][j] + 1;
                q.push({i+1, j});
            }
            if(isValid(i-1, j, row, col) && ans[i-1][j] == -1){
                ans[i-1][j] = ans[i][j] + 1;
                q.push({i-1, j});
            }
            if(isValid(i, j+1, row, col) && ans[i][j+1] == -1){
                ans[i][j+1] = ans[i][j] + 1;
                q.push({i, j+1});
            }
            if(isValid(i, j-1, row, col) && ans[i][j-1] == -1){
                ans[i][j-1] = ans[i][j] + 1;
                q.push({i, j-1});
            }
        }
        
        return ans;

    }
};