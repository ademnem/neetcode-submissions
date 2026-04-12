class Solution {
public:
    bool isValid(string s) {
        std::stack<char> opens;
        for (char c : s) {
            switch (c) {
                case ')':
                    if (opens.empty() || opens.top() != '(')
                        return false;
                    opens.pop();
                    break;
                case '}':
                     if (opens.empty() || opens.top() != '{')
                        return false;
                    opens.pop();
                    break;
                case ']':
                    if (opens.empty() || opens.top() != '[')
                        return false;
                    opens.pop();
                    break;
                default:
                    opens.push(c);
            }
        }
        return opens.empty();
    }
};
