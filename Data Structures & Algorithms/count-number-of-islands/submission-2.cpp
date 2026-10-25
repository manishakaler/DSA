class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c, int rt, int ct){
       
        if( r < 0|| c < 0 || r >= rt || c>=ct || grid[r][c] != '1'){
            return;
        }

        //ct = grid[r].size();
        grid[r][c] = '0';


        dfs(grid, r-1, c, rt, ct);
        dfs(grid, r+1, c, rt, ct);
        dfs(grid, r, c+1, rt, ct);
        dfs(grid, r, c-1, rt, ct);

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int rt = grid.size();
        int ct = grid[0].size(); // as 1<=rt<=100
        int noi = 0;
        for(int i = 0; i < rt; ++i){
            //int ct = grid[i].size();
            for(int j = 0; j < ct; ++j){
                if(grid[i][j] == '1'){
                    noi++;
                    dfs(grid, i, j, rt, ct);
                }
            }
        }

        return noi;

    }
};
