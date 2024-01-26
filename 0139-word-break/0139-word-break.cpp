class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n, false);
        for(int i=0; i<n; i++){
            for(string &str: wordDict){
                if(i>=str.size()-1 && (i==str.size()-1 || dp[i-str.size()])){
                    if(s.substr(i-str.size()+1, str.size()).compare(str)==0){
                        dp[i] = true;
                        break;
                    } 
                }
            }
        }
        
        return dp[n-1];
    }
};