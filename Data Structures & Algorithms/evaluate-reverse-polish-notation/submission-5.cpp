class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string op = tokens.back();
        tokens.pop_back();
        if (regex_match(op, regex{"-?[0-9]+"}))
            return atoi(op.c_str()); 
        
        int num2 = evalRPN(tokens);
        int num1 = evalRPN(tokens);
        switch(op[0]) {
            case '*':
                return num1 * num2;
            case '/':
                return num1 / num2;
            case '-':
                return num1 - num2;
            case '+':
                return num1 + num2;
            default:
                throw 0;
        }
    }
};
