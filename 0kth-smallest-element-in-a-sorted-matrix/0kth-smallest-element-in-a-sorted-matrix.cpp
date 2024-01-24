class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int> pq;
        int count = 0;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                if(count++ < k) pq.push(matrix[i][j]);
                else{
                    if(matrix[i][j] < pq.top()){
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        
        return pq.top();
    }
};