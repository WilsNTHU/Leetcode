class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> result;
        
        for(int i=temperatures.size()-1; i>=0; i--){
            while(!s.empty() && temperatures[i]>=temperatures[s.top()]) s.pop();
            if(s.empty()) result.push_back(0);
            else result.push_back(s.top()-i);
            s.push(i);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};