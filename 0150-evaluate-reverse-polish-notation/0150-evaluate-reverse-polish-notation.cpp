class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> st({"+", "-", "*", "/"});
        stack<int> s;
        
        for(string c: tokens){
            if(st.find(c) == st.end()) s.push(stoi(c));
            else{
                int x = s.top(); s.pop();
                int y = s.top(); s.pop();

                if(c == "+") s.push(y+x);
                else if(c == "-") s.push(y-x);
                else if(c == "*") s.push(y*x);
                else s.push(y/x);
            }
        }
        
        return s.top();
    }
};