class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> buffer;
        helper(result, buffer, n, k, 1);
        return result;
    }
    
    void helper(vector<vector<int>> &arr, vector<int> &buffer, int &n, int k, int num){
        if(k == 0){
            arr.push_back(buffer);
            return;
        }
        
        for(int i=num; i<=n; i++){
           buffer.push_back(i);
           helper(arr, buffer, n, k-1, i+1);
           buffer.pop_back();
        }
        
        return;
    }
    
};