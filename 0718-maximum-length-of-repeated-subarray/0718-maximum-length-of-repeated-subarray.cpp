class Solution {
public:
    int helper(vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp
              , int i, int j, int &max_val){
        if(i>=nums1.size() || j>=nums2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(nums1[i] == nums2[j]){
            dp[i][j] = 1 + helper(nums1, nums2, dp, i+1, j+1, max_val);
            max_val = max(max_val, dp[i][j]);
        } 
        else dp[i][j] = 0;
           
        helper(nums1, nums2, dp, i+1, j, max_val);
        helper(nums1, nums2, dp, i, j+1, max_val);
        
        return dp[i][j];
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len_1 = nums1.size();
        int len_2 = nums2.size();
        
        vector<vector<int>> dp(len_1, vector<int>(len_2, -1));
        int max_val = INT_MIN;
        helper(nums1, nums2, dp, 0, 0, max_val);
        
        return (max_val == INT_MIN) ? 0 : max_val;
    }
};