class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int steps = 0, result = INT_MAX;
        queue<string> q;
        unordered_set<string> s(deadends.begin(), deadends.end());
        if(s.count("0000")) return -1;
        q.push("0000");
        
        for(; !q.empty(); steps++){
            for(int i=q.size(); i>0; i--){
                string str = q.front();
                q.pop();
                if(str == target) return steps;
                for(int i=0; i<4; i++){
                    char c = str[i];
                    str[i] = (str[i]=='9') ? '0' : str[i]+1;
                    if(!s.count(str)){
                        q.push(str);
                        s.insert(str);
                    }
                    str[i] = c;
                }
                for(int i=0; i<4; i++){
                    char c = str[i];
                    str[i] = (str[i]=='0') ? '9' : str[i]-1;
                    if(!s.count(str)){
                        q.push(str);
                        s.insert(str);
                    }
                    str[i] = c;
                }
            }
        }
        
        return -1;
    }
};