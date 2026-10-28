class Solution {
public:
//dfs
    void dfsIsland(int crow, int ccol, int rowTotal, int colTotal, vector<vector<char>>& grid ){
        if(crow < 0 || crow >=rowTotal || ccol < 0 || ccol >=colTotal || grid[crow][ccol] == '0'){
            return;
        }

        grid[crow][ccol] = '0';
        dfsIsland(crow-1,ccol,rowTotal,colTotal,grid);
        dfsIsland(crow+1,ccol,rowTotal,colTotal,grid);
        dfsIsland(crow,ccol-1,rowTotal,colTotal,grid);
        dfsIsland(crow,ccol+1,rowTotal,colTotal,grid);

    }
    int numIslands(vector<vector<char>>& grid){
        int rowTotal = grid.size();
        int colTotal = grid[0].size();
        int totalIslands = 0;
        for(int i = 0; i < rowTotal; ++i){
            for(int j = 0; j < colTotal; ++j){
                if(grid[i][j] == '1'){
                    totalIslands ++;
                    dfsIsland(i,j,rowTotal,colTotal,grid);
                }
            }
        }

        return totalIslands;

        //Time complexity - O(m*n)*O(1) = 
        //space complexity - O(m*n) - recursion stack
    }
};
