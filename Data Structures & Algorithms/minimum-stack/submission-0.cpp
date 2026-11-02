class MinStack {
    vector<int> minValue;
    vector<int> stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
        if (!minValue.size()) {
            minValue.push_back(val);
        } else {
            if (val <= minValue.back()) {
                minValue.push_back(val);
            }
        }
    }
    
    void pop() {
        if (minValue.back() == stack.back()) {
            minValue.pop_back();
        }
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minValue.back();
    }
};