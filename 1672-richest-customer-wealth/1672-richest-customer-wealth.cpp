class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int result = 0;
        vector<vector<int>>::iterator it;
        for(it=accounts.begin(); it != accounts.end(); it++){
            result = max(result, accumulate((*it).begin(), (*it).end(), 0));
        }
        
        return result;
    }
};