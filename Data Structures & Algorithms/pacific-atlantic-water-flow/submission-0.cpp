class Solution {
private:
    int rt;
    int ct;
public:
    void dfs(vector<vector<int>>& heights, int r, int c, set<pair<int,int>>& hs, int currHt, set<pair<int,int>>&visited){


        if(r < 0 || r >=rt || c<0 || c >=ct || heights[r][c] < currHt || visited.count({r,c})== 1){
            return;
        }

        
        visited.insert({r,c});
        hs.insert({r,c});
        dfs(heights, r-1,c, hs, heights[r][c], visited);
        dfs(heights, r+1,c, hs, heights[r][c], visited);
        dfs(heights, r,c-1, hs, heights[r][c], visited);
        dfs(heights, r,c+1, hs, heights[r][c], visited);
       
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rt = heights.size();
        ct = heights[0].size();
        int n = rt*ct;
        set<pair<int,int>>visited;
        set<pair<int,int>>pacific;
        set<pair<int,int>>atlantic;

        dfs(heights,0, 0, pacific, 0, visited);
        for(int i = 0 ; i < rt; ++i){
             dfs(heights,i, 0, pacific, 0, visited);
        }

        for(int j = 0 ; j < ct; ++j){
             dfs(heights,0, j, pacific, 0, visited);
        }

        visited.clear();
        dfs(heights,rt-1, ct - 1 , atlantic, 0, visited);
        for(int i = 0 ; i < rt; ++i){
           dfs(heights,i, ct-1, atlantic, 0, visited);
        }

        for(int j = 0 ; j < ct; ++j){
           dfs(heights,rt - 1, j, atlantic, 0, visited);
        }

        vector<vector<int>> res;
        for(int p = 0; p < rt ; ++p){
            for(int q = 0; q < ct; ++q){
               if(pacific.count({p,q}) && atlantic.count({p,q})){
                res.push_back({p,q});
                }
            }
        }
           

        return res;

    }
};
