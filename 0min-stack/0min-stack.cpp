class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        if(s.empty()) s.emplace_back(val, val);
        else s.emplace_back(val, (val < s.back().second) ? val : s.back().second);
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s.back().first;
    }
    
    int getMin() {
        return s.back().second;
    }
private: 
    vector<pair<int, int>> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */