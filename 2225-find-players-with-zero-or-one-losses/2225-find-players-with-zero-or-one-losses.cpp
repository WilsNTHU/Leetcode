class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> answer;
        vector<int> t0, t1;
        map<int, int> player, lost;
        
        for(auto &p: matches){
            if(!player[p[0]]) player[p[0]] = 1;
            if(!player[p[1]]) player[p[1]] = 1;
            
            if(!lost[p[1]]) lost[p[1]] = 1;
            else lost[p[1]]++;
        }
        
        for(auto &it: player){
            if(lost.find(it.first) == lost.end()) t0.push_back(it.first);
            else if(lost[it.first] == 1) t1.push_back(it.first);
        }
        
        answer.push_back(t0); answer.push_back(t1);
        return answer;
        
    }
};