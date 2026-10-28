class Solution {
public:
    void backtrackParenthesis(string& current, int open, int close, int n, vector<string>& results){
        if(current.length() == 2*n){
            results.push_back(current);
            return;
        }

        if(open < n){
            current.push_back('(');
            backtrackParenthesis(current, open + 1, close, n, results);
            current.pop_back();
        }

        if(open > close){
            current.push_back(')');
            backtrackParenthesis(current, open, close + 1, n, results);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        vector<string>results;
        string current = "";
        backtrackParenthesis(current, open, close, n, results);

        return results;

    }
};
