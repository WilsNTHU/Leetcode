#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// class Solution {
// public:
//     int helper(vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp
//               , int i, int j, int &max_val){
//         if(i>=nums1.size() || j>=nums2.size()) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
        
//         if(nums1[i] == nums2[j]){
//             dp[i][j] = 1 + helper(nums1, nums2, dp, i+1, j+1, max_val);
//             max_val = max(max_val, dp[i][j]);
//         } 
//         else dp[i][j] = 0;
           
//         helper(nums1, nums2, dp, i+1, j, max_val);
//         helper(nums1, nums2, dp, i, j+1, max_val);
        
//         return dp[i][j];
//     }
    
//     int findLength(vector<int>& nums1, vector<int>& nums2) {
//         int len_1 = nums1.size();
//         int len_2 = nums2.size();
        
//         vector<vector<int>> dp(len_1, vector<int>(len_2, -1));
//         int max_val = INT_MIN;
//         helper(nums1, nums2, dp, 0, 0, max_val);
        
//         return (max_val == INT_MIN) ? 0 : max_val;
//     }
// };

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int max_val = INT_MIN;

        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    max_val = max(max_val, dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        
        return (max_val == INT_MIN) ? 0 : max_val;
    }
};