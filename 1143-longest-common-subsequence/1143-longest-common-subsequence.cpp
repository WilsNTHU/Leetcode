class Solution {
public:
    int helper(vector<vector<int>> &dp, string &text1, string &text2, int i, int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j]) dp[i][j] = helper(dp, text1, text2, i-1, j-1) + 1;
        else{
            dp[i][j] = max(helper(dp, text1, text2, i-1, j), 
                           helper(dp, text1, text2, i, j-1));
        }
        return dp[i][j];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, -1));
        for(int i=0; i<=len1; i++) dp[i][0] = 0;
        for(int i=0; i<=len2; i++) dp[0][i] = 0;
        
        for(int i=1; i<=len1; i++)
            for(int j=1; j<=len2; j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        
        return dp[len1][len2];
    }
};