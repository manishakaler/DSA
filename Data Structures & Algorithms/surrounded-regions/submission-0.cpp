class Solution {
private: 
    int rt;
    int ct;
public:
    void dfs(vector<vector<char>>& board, int r, int c){
        if( r <0 || r >= rt || c <0 || c>=ct || board[r][c] == 'X' || board[r][c] == '#'){
            return;
        }

        board[r][c] = '#';

        dfs(board,r-1,c);
        dfs(board,r+1,c);
        dfs(board,r,c-1);
        dfs(board,r,c+1);
    }
    void solve(vector<vector<char>>& board) {
        rt = board.size();
        ct = board[0].size();

        for(int i = 0; i < rt ; ++i){
            if(board[i][0] == 'O'){
                dfs(board, i, 0);
            }
            if(board[i][ct-1]== 'O'){
                dfs(board,i,ct-1);
            }
        }
        for(int j = 0; j < ct ; ++j){
            if(board[0][j] == 'O'){
                dfs(board, 0, j);
            }
            if(board[rt-1][j] == 'O'){
                dfs(board, rt-1, j);
            }
        }

        for(int i = 0; i<rt; ++i){
            for(int j = 0; j<ct; ++j ){
                if(board[i][j] == '#'){
                    
                        board[i][j] = 'O';
                } else if(board[i][j] == 'O'){
                        board[i][j] = 'X';
                    }
                
            }
        }
       
    }
};
