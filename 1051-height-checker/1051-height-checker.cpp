class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> expected(heights);
        
        bool hasSwapped = true;
        while(hasSwapped){
            hasSwapped = false;
            for(int i=0; i<=n-2; i++){
                for(int j=i+1; j<=n-1; j++){
                    if(expected[j] < expected[i]){
                        swap(expected[j], expected[i]);
                        hasSwapped = true;
                    }
                }
            }    
        }
        
        int answer = 0;
        for(int i=0; i<n; i++){
            if(expected[i] != heights[i]) answer++;
        }
        
        return answer;
    }
};