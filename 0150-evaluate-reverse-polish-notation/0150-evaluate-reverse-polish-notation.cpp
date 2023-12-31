class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> st({"+", "-", "*", "/"});
        stack<string> s;
        
        for(string c: tokens){
            if(st.find(c) == st.end()) s.push(c);
            else{
                int x = stoi(s.top());
                s.pop();
                int y = stoi(s.top());
                s.pop();
                if(c == "+") s.push(to_string(y+x));
                else if(c == "-") s.push(to_string(y-x));
                else if(c == "*") s.push(to_string(y*x));
                else s.push(to_string(y/x));
            }
        }
        
        return stoi(s.top());
    }
};