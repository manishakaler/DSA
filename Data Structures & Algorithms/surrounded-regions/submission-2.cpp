class Solution {
   public:
    void trackReachFromEdges(vector<vector<char>>& board, int rowTotal, int colTotal, int row, int col) {
        if (row < 0 || col < 0 || row >= rowTotal || col >= colTotal || board[row][col] != 'O') {
            return;
        }

        board[row][col] = '#';
        trackReachFromEdges(board, rowTotal,colTotal, row-1,col);
        trackReachFromEdges(board, rowTotal,colTotal, row+1,col);
        trackReachFromEdges(board, rowTotal,colTotal, row,col-1);
        trackReachFromEdges(board, rowTotal,colTotal, row,col+1);
    }
    void solve(vector<vector<char>>& board) {
        // dfs vibe

        int rowTotal = board.size();
        int colTotal = board[0].size();

        for (int i = 0; i < rowTotal; ++i) {
            if (board[i][0] == 'O') {
                trackReachFromEdges(board, rowTotal, colTotal, i, 0 );
            }

            if (board[i][colTotal - 1]) {
                trackReachFromEdges(board, rowTotal, colTotal, i, colTotal -1 );
            }
        }

        for (int j = 0; j < colTotal; ++j) {
            if (board[0][j] == 'O') {
                trackReachFromEdges(board, rowTotal, colTotal, 0, j );
            }

            if (board[rowTotal - 1][j]) {
                trackReachFromEdges(board, rowTotal, colTotal, rowTotal - 1 , j );
            }
        }

        for(int i = 0; i < rowTotal; ++i){
            for(int j = 0; j < colTotal; ++j){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                } else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
