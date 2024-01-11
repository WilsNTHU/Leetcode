class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n-1;
        while(x<m && y>=0){
            if(matrix[x][y] == target) return true;
            else if(target < matrix[x][y]) y--;
            else if(target > matrix[x][y]) x++; 
        }
        
        return false;
    }
    
};