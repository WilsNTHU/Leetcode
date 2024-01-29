class Solution {
public:
    int helper(vector<vector<int>>& costs, vector<vector<int>> &dp, 
               int i, int color){
        if(i >= costs.size()) return 0;
        if(dp[i][color] != -1) return dp[i][color];
        
        if(color == 0)
            dp[i][0] = costs[i][0] + min(helper(costs, dp, i+1, 1), 
                                          helper(costs, dp, i+1, 2));
        else if(color == 1) 
            dp[i][1] = costs[i][1] + min(helper(costs, dp, i+1, 0), 
                                          helper(costs, dp, i+1, 2));
        else
            dp[i][2] = costs[i][2] + min(helper(costs, dp, i+1, 0), 
                                          helper(costs, dp, i+1, 1));
        
        return dp[i][color];
    }
    
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        int min_val = INT_MAX;
        for(int i=0; i<3; i++)
            min_val = min(min_val, helper(costs, dp, 0, i));
        
        return min_val;
    }
};