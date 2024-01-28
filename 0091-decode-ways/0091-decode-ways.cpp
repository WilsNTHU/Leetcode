class Solution {
public:
    int helper(string &s, vector<int> &dp, int i){
        if(i >= s.size()) return 1;
        if(s[i] == '0') return 0;
        
        if(dp[i] != -1) return dp[i];

        int one_digit = helper(s, dp, i+1);
        
        int two_digit = 0;
        if(i != s.size()-1 && (s[i]=='1' || (s[i] =='2' && s[i+1] <= '6')))
            two_digit = helper(s, dp, i+2);
        
        return dp[i] = one_digit + two_digit;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        
        vector<int> dp(n, -1);
        return helper(s, dp, 0);
    }
};