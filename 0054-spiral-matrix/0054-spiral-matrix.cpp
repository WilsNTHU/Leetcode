class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty() || matrix[0].empty()) return result;
        
        int count = 0;
        int i=0, j=0;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, down = m - 1, left = 0, right = n-1;
        
        
        while(left<=right && top<=down){
            for(int j=left; j<=right; j++){
                result.push_back(matrix[top][j]);
            }
            top++;
            
            for(int i=top; i<=down; i++){
                result.push_back(matrix[i][right]);
            }
            right--;
            
            if(top <= down){
                for(int j=right; j>=left; j--){
                    result.push_back(matrix[down][j]);
                }
                down--;
            }
            
            if(left <= right){
                for(int i=down; i>=top; i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            
        }
        
        return result;
    }
};