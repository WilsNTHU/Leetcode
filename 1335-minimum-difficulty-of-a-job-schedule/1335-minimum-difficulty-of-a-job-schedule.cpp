class Solution {
public:
    int helper(vector<vector<int>> &dp, vector<int>& job, int d, int i, int day){
        if(dp[i][day] != INT_MAX) return dp[i][day];
        
        int n = job.size();
        int hardest = INT_MIN;
        for(int j=i; j<=n-1-(d-day); j++){
            hardest = max(hardest, job[j]);
            dp[i][day] = min(dp[i][day], hardest + 
                             helper(dp, job, d, j+1, day+1));
        }
        return dp[i][day];
            
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d > n) return -1;
        
        vector<vector<int>> dp(n, vector<int>(d+1, INT_MAX));
        dp[n-1][d] = jobDifficulty[n-1];
        for(int i=n-2; i>=d-1; i--)
            dp[i][d] = max(jobDifficulty[i], dp[i+1][d]);
        
        return helper(dp, jobDifficulty, d, 0, 1);
    }
    
    
    // each day while iterate from job[day-1] to job[n-1-day]
    // recurrence relation dp[i][day] = min(hardest + dp[j+1][day+1])
    // where i <= j <= n-1-day and hardest = max(job[i],job[j])
};