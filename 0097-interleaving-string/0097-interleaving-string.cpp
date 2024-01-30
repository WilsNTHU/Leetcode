class Solution {
public:
    int helper(vector<vector<int>> &dp, string &s1, string &s2, string &s3
              , int i, int j){
        if(i+j >= s3.size()) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int len_1 = s1.size(), len_2 = s2.size();
        
        bool ans = false;
        if(i<len_1 && s1[i] == s3[i+j]) ans |= helper(dp, s1, s2, s3, i+1, j);
        if(j<len_2 && s2[j] == s3[i+j]) ans |= helper(dp, s1, s2, s3, i, j+1);
        
        return dp[i][j] = (int)ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int len_1 = s1.size();
        int len_2 = s2.size();
        int len_3 = s3.size();
        
        if(len_1 + len_2 != len_3) return false;
        
        vector<vector<int>> dp(len_1+1, vector<int>(len_2+1, -1));
        return helper(dp, s1, s2, s3, 0, 0);
        
    }
};