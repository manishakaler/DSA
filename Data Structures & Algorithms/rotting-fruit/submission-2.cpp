class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rt = grid.size();
        int ct = grid[0].size();

        queue<pair<int,int>>visited_oranges;
        int fresh = 0;

        for(int i = 0 ; i < rt; ++i){
            for(int j = 0; j< ct; ++j){
                switch(grid[i][j]){
                    case 1:
                    fresh++;
                    continue;
                    case 2:
                    visited_oranges.push({i,j});
                    continue;
                }
            }
        }
        if(fresh == 0) return 0;
        if(visited_oranges.empty()) return -1;
        int minutes = 0;

        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(!visited_oranges.empty() && fresh > 0){
            int size = visited_oranges.size();
            for(int s = 0 ; s < size; ++s){
                pair<int,int> p = visited_oranges.front();
                visited_oranges.pop();
               
                for(pair d: directions){
                    int cr = p.first + d.first;
                    int cc =  p.second + d.second;
                    if(cr < 0 || cr >=rt || cc < 0 || cc >= ct){
                        continue;
                    } else {
                        if(grid[cr][cc] == 1){
                            grid[cr][cc] = 2;
                            fresh--;
                            visited_oranges.push({cr,cc});
                        }
                    }
                }
            }
            minutes++;
        }

        return fresh == 0? minutes: -1;
    }
};
