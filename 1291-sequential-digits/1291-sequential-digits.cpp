class Solution {
public:
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int sum;
        
        for(int i=1; i<=9; i++){
            sum = i;
            for(int j=i+1; j<=9; j++){
                sum = sum*10 + j;
                if(sum > high) break;
                if(sum>=low && sum<=high) ans.push_back(sum);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};