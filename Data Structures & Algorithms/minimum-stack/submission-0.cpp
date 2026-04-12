class MinStack {
    std::stack<int> stack;
    std::stack<int> min;
public:
    MinStack() : stack(), min() {}
    
    void push(int val) {
        if (stack.empty()) {
            stack.push(val);
            min.push(val);
        } else {
            if (val < min.top())
                min.push(val);
            else
                min.push(min.top());
            stack.push(val);
        }
    }
    
    void pop() {
        stack.pop();
        min.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return min.top();
    }
};
