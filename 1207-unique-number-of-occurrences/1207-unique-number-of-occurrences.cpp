class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        for(int &it: arr) map[it]++;
        
        unordered_set<int> s;
        for(auto &it: map){
            if(s.count(it.second)) return false;
            s.insert(it.second);
        }
        
        return true;
    }
};