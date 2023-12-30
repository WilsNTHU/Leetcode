class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        stack<int> s;
        vector<int> result(len, 0);
        
        for(int i=len-1; i>=0; i--){
            while(!s.empty() && temperatures[i]>=temperatures[s.top()]) s.pop();
            if(!s.empty()) result[i] = s.top()-i;
            s.push(i);
        }
        
        return result;
    }
};