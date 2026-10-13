class Solution {
public:
    void adjNodeDfs(vector<vector<char>>& grid, int r, int c){
        int rt = grid.size();
        int ct = grid[0].size();
        if(r < 0 || c < 0 || r >= rt || c >= ct || grid[r][c] == '0')
        return;

        grid[r][c] = '0';
        adjNodeDfs(grid,r,c-1);
        adjNodeDfs(grid,r,c+1);
        adjNodeDfs(grid,r-1,c);
        adjNodeDfs(grid,r+1,c);
    }
    int numIslands(vector<vector<char>>& grid) {
        int totalRows = grid.size();
        int totalCols = grid[0].size();
        int numIslands = 0;

        for(int i = 0; i < totalRows; ++i){
            for(int j = 0; j < totalCols; ++j){
                if(grid[i][j] == '1'){
                    numIslands++;
                    adjNodeDfs(grid, i, j);
                }

                
            }
        }
        return numIslands;
    }
};
