class Solution {
private:
    int rowTotal;
    int colTotal;
public:
    bool backtrackWordSearch(vector<vector<char>>& board, string word, int widx, int row, int col){

        if(widx == word.length()){
            return true;
        }

        if(row <0 || col < 0 || row >= rowTotal || col >=colTotal || board[row][col]!=word[widx]){
            return false;
        }

        char original = board[row][col];
        board[row][col] = '#';
                
        bool found = backtrackWordSearch(board, word, widx+1, row-1, col ) || backtrackWordSearch(board, word, widx+1, row+1, col ) || backtrackWordSearch(board, word, widx+1, row, col-1 ) || backtrackWordSearch(board, word, widx+1, row, col+1) ;
            
        board[row][col] = original;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int ws = word.length();
        rowTotal = board.size();
        colTotal = board[0].size();

        int widx = 0;
        for(int i = 0; i<rowTotal; ++i){
            for(int j=0; j < colTotal; ++j){
                if(backtrackWordSearch(board, word, widx, i, j )){
                    return true;
                }
            }
        }
        

        return false;
    }
};
