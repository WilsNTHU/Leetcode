class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
    
    bool helper(vector<vector<char>>& board){
        for(int row=0; row<9; row++)
            for(int col=0; col<9; col++)
                if(board[row][col]=='.'){
                    for(char val='1'; val<='9'; val++)
                        if(isSafe(board, row, col, val)){
                            board[row][col] = val;
                            if(helper(board)) return true;
                            else board[row][col] = '.';
                        }
                    return false;
                }
                    
            
        
        
        return true;
    }
    
    bool isSafe(vector<vector<char>>& board, int row, int col, int val){
        // examine same row
        for(int j=0; j<9; j++) 
            if(board[row][j] == val) return false;
        
        // examine same col
        for(int i=0; i<9; i++)
            if(board[i][col] == val) return false;
        
        // examine same block
        int i=row/3, j=col/3;
        i *= 3; j *= 3;
        for(int k1=0; k1<3; k1++)
            for(int k2=0; k2<3; k2++)
                if(board[i+k1][j+k2]==val) return false;
        
        return true;
    }
};