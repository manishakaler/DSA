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

        //time c: \(O(4^n\sqrt{\vphantom n 1})\)
        //space complexitu : Space	Complexity	Reason
        // current	\(O(n)\)	Holds at most \(2n\) characters
        // Recursion stack	\(O(n)\)	Maximum depth is \(2n\)
        // results	\(O(nC_n)\)	\(C_n\) strings, each of length \(2n\)

        // Auxiliary space, excluding the output:
        // \[
        // \boxed{O(n)}
        // \]

        // Total space, including output:
        // \[
        // \boxed{O(nC_n)}
        // \]

    }
};
