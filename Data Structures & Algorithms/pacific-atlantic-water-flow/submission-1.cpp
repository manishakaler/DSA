class Solution {
private:
    int rt;
    int ct;
public:
    void dfs(vector<vector<int>>& heights, int r, int c, int currHt, vector<vector<bool>>&visited){


        if(r < 0 || r >=rt || c<0 || c >=ct || heights[r][c] < currHt || visited[r][c] == true){
            return;
        }

        
        visited[r][c] = true;
       
        dfs(heights, r-1,c, heights[r][c], visited);
        dfs(heights, r+1,c, heights[r][c], visited);
        dfs(heights, r,c-1, heights[r][c], visited);
        dfs(heights, r,c+1, heights[r][c], visited);
       
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rt = heights.size();
        ct = heights[0].size();
        int n = rt*ct;
        vector<vector<bool>>pacific(rt, vector<bool>(ct,false));
        vector<vector<bool>>atlantic(rt, vector<bool>(ct,false));
        

       
        for(int i = 0 ; i < rt; ++i){
             dfs(heights,i, 0, 0, pacific);
        }

        for(int j = 0 ; j < ct; ++j){
             dfs(heights,0, j, 0, pacific);
        }

        
      
        for(int i = 0 ; i < rt; ++i){
           dfs(heights,i, ct-1, 0, atlantic);
        }

        for(int j = 0 ; j < ct; ++j){
           dfs(heights,rt - 1, j, 0, atlantic);
        }

        vector<vector<int>> res;
        for(int p = 0; p < rt ; ++p){
            for(int q = 0; q < ct; ++q){
               if(pacific[p][q] && atlantic[p][q]){
                res.push_back({p,q});
                }
            }
        }
           

        return res;

    }
};
