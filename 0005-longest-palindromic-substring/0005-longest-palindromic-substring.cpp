class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int dp[n][n];
        
        memset(dp, 0, sizeof(dp));
        
        int max_len = 1;
        int start_idx;
        
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
            start_idx = i;
        } 
        for(int i=0; i<=n-2; i++){
            if(s[i] == s[i+1]){
                max_len = 2;
                start_idx = i;
                dp[i][i+1] = 1;
            }
        }
        
        for(int l=3; l<=n; l++){
            for(int i=0; i< n-l+1; i++){
                int j = l + i - 1;
                if(dp[i+1][j-1] && (s[i]==s[j])){
                    dp[i][j] = 1;
                    
                    if(max_len < l){
                        max_len = l;
                        start_idx = i;
                    }
                }
            }
        }
        
        return s.substr(start_idx, max_len);
    }
};