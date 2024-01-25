class Solution {
public:
    int helper(vector<int>&nums, vector<int>& multipliers, vector<vector<long>> &dp,
          int i, int left){
        if(i == multipliers.size()) return 0;
        if(dp[i][left] != -1) return dp[i][left];
        int right = nums.size()-1 - (i-left);
        return dp[i][left] = max(
        (long)nums[left]*multipliers[i] + helper(nums, multipliers, dp, i+1, left+1),
        (long)nums[right]*multipliers[i] + helper(nums, multipliers, dp, i+1, left));
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        int n = nums.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
        for(int i=m-1; i>=0; i--)
            for(int left=i; left>=0; left--){
                int mult = multipliers[i];
                int right = n-1 - (i-left);
                dp[i][left] = max(
                    nums[left] * mult + dp[i+1][left+1],
                    nums[right] *mult + dp[i+1][left]
                );
            }
        
        return dp[0][0];
    }
};