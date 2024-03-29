class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(nums, dp, n-1);
    }
    
    int helper(vector<int>& nums, vector<int> &dp, int n){
        if(n == 0) return nums[0];
        if(n == 1) return max(nums[0], nums[1]);
        
        if(dp[n] == -1) 
            return dp[n] = max(helper(nums, dp, n-1), helper(nums, dp, n-2)+nums[n]);
        return dp[n];
    }
};