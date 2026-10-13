class Solution {
public:
   
    int orangesRotting(vector<vector<int>>& grid) {
        int rt = grid.size();
        int ct = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>>nodeQueue;

        for(int r = 0; r<rt; ++r){
            for(int c = 0; c<ct; ++c){
                if(grid[r][c] == 2){
                    nodeQueue.push({r,c});
                }else if(grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        if(fresh == 0) return 0;
        vector<pair<int,int>>directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int minutes=0;
        while(!nodeQueue.empty() && fresh > 0){
            int size = nodeQueue.size();
            minutes++;
            for(int i = 0; i < size ; ++i){
                pair<int,int> curr = nodeQueue.front();
                nodeQueue.pop();
              
                for(auto dir : directions){
                    int row = curr.first +dir.first;
                    int col = curr.second + dir.second;

                    if(row >= 0 && col >=0 && row <rt && col<ct && grid[row][col] ==1)
                    {
                        grid[row][col]=2;
                        nodeQueue.push({row,col});
                        fresh--;
                    }
                }
            }
        }

        return fresh == 0? minutes: -1;      

    }
};
