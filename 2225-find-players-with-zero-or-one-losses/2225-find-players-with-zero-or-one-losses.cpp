class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> answer;
        vector<int> t0, t1;
        unordered_map<int, int> lost;
        
        for(auto &p: matches){
            if(!lost[p[0]]) lost[p[0]] = 0;
            lost[p[1]]++;
        }
        
        for(auto &p: lost){
            if(p.second == 0) t0.push_back(p.first);
            else if(p.second == 1) t1.push_back(p.first);
        }
        
        sort(t0.begin(), t0.end());
        sort(t1.begin(), t1.end());
        answer.push_back(t0); answer.push_back(t1);
        return answer;
        
    }
};