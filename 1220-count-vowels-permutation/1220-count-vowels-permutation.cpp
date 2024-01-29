class Solution {
public:
    int helper(vector<vector<int>> &dp, int n, int i, int vowel){
        if(i == (n-1)) return 1;
        if(dp[i][vowel] != -1) return dp[i][vowel];
        
        long long temp = 0;
        if(vowel == 0){
            temp += helper(dp, n, i+1, 1);
            temp += helper(dp, n, i+1, 4);
            temp += helper(dp, n, i+1, 2);
        } 
        if(vowel == 1){
            temp += helper(dp, n, i+1, 0);
            temp += helper(dp, n, i+1, 2);
        } 
        if(vowel == 2){
            temp += helper(dp, n, i+1, 1);
            temp += helper(dp, n, i+1, 3);
        } 
        if(vowel == 3) temp = helper(dp, n, i+1, 2);
        if(vowel == 4){
            temp += helper(dp, n, i+1, 2);
            temp += helper(dp, n, i+1, 3);
        } 
        
        return dp[i][vowel] = temp % (int)(1e9 + 7);
    }
    
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n, vector<int>(5, -1));
        
        int ans = 0;
        for(int i=0; i<5; i++){
            ans += helper(dp, n, 0, i);
            ans = ans % (int)(1e9 + 7);
        } 
        
        return ans;
    }
};