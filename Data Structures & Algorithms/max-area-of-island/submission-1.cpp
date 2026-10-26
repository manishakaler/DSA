#include<limits>

class Solution {
private:
    int maxArea = 0;
    int rowTotal;
    int colTotal;
public:
    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || r >= rowTotal || c < 0 || c >= colTotal || grid[r][c] != 1){
            return 0;
        }

        int currArea = 1;
        grid[r][c] = 0;

        currArea+=dfs(grid, r+1, c);
        currArea+=dfs(grid, r-1, c);
        currArea+=dfs(grid, r, c+1);
        currArea+=dfs(grid, r, c-1);

        return currArea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rowTotal = grid.size();
        colTotal = grid[0].size();

        for(int i = 0; i < rowTotal; ++i){
            for(int j = 0; j < colTotal; ++j){
                if(grid[i][j] == 1){
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }

        return maxArea;
    }
};
