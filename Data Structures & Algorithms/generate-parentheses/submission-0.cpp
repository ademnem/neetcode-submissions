class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        backtrack(res, stack, 0, 0, n);
        return res;
    }

    void backtrack(vector<string>& res, string& stack, int open, int close, int n) {
        if (n == open && open == close) {
            res.push_back(stack);
            return;
        }
        
        if (open < n) {
            stack.push_back('(');
            backtrack(res, stack, open + 1, close, n);
            stack.pop_back();
        }

        if (close < open) {
            stack.push_back(')');
            backtrack(res, stack, open, close + 1, n);
            stack.pop_back();
        }
    }
};
