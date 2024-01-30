class Solution {
public:
    int helper(vector<int>& days, vector<int>& costs, vector<int> &dp, int i){
        if(dp[days[i]] != -1) return dp[days[i]];
        
        int one_day, seven_day, thirty_day;
        
        auto it_one = upper_bound(days.begin(), days.end(), days[i]);
        if(it_one != days.end()) 
            one_day = costs[0] + helper(days, costs, dp, it_one-days.begin());
        else one_day = costs[0];
        
        auto it_seven = upper_bound(days.begin(), days.end(), days[i]+6);
        if(it_seven != days.end())
            seven_day = costs[1] + helper(days, costs, dp, it_seven-days.begin());
        else seven_day = costs[1];
        
        auto it_thirty = upper_bound(days.begin(), days.end(), days[i]+29);
        if(it_thirty != days.end())
            thirty_day = costs[2] + helper(days, costs, dp, it_thirty-days.begin());
        else thirty_day = costs[2];
        
        return dp[days[i]] = min(one_day, min(seven_day, thirty_day));
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(365+1, -1);
        return helper(days, costs, dp, 0);
    }
};