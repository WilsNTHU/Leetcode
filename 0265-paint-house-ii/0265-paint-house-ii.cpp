class Solution {
public:
    int helper(vector<vector<int>>& costs, vector<vector<int>> &dp, 
               int i, int color){
        if(i >= costs.size()) return 0;
        if(dp[i][color] != -1) return dp[i][color];
        
        int min_val = INT_MAX;
        
        for(int k=0; k<costs[0].size(); k++)
            if(k != color) 
                min_val = min(min_val, costs[i][k] + helper(costs, dp, i+1, k));
        
        return dp[i][color] = min_val;
    }
    
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        
        vector<vector<int>> dp(n, vector<int>(k, -1));
        int min_val = INT_MAX;
        for(int i=0; i<k; i++)
            min_val = min(min_val, helper(costs, dp, 0, i));
        
        return min_val;
    }
};