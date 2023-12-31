class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(string c: tokens){
            if(c == "+"){
                int x = stoi(s.top());
                s.pop();
                int y = stoi(s.top());
                s.pop();
                s.push(to_string(y+x));
            }
            else if(c == "-"){
                int x = stoi(s.top());
                s.pop();
                int y = stoi(s.top());
                s.pop();
                s.push(to_string(y-x));
            }
            else if(c == "*"){
                int x = stoi(s.top());
                s.pop();
                int y = stoi(s.top());
                s.pop();
                s.push(to_string(y*x));
            }
            else if(c == "/"){
                int x = stoi(s.top());
                s.pop();
                int y = stoi(s.top());
                s.pop();
                s.push(to_string(y/x));
            }
            else s.push(c);
        }
        
        return stoi(s.top());
    }
};