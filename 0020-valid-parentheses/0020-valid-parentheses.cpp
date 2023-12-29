class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(auto c: s){
            if(c == '(') t.push(c);
            else if(c == '[') t.push(c);
            else if(c == '{') t.push(c);
            else if(c == ')'){
                if(!t.empty() && t.top() == '(') t.pop();
                else return false;
            }
            else if(c == ']'){
                if(!t.empty() && t.top() == '[') t.pop();
                else return false;
            }
            else if(c == '}'){
                if(!t.empty() && t.top() == '{') t.pop();
                else return false;
            }
            else continue;
        }
        
        if(t.empty()) return true;
        else return false;
    }
};