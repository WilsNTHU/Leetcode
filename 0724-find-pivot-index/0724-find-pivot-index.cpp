class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_sum(n);
        vector<int> right_sum(n);
        
        
        for(int i=0; i<n; i++){
            if(i == 0){
                left_sum[i] = 0;
                right_sum[i] = accumulate(nums.begin()+i+1, nums.end(),0);
            } 
            else if(i == n-1){
                left_sum[i] = accumulate(nums.begin(), nums.begin()+i, 0);
                right_sum[i] = 0;
            } 
            else{
                left_sum[i] = accumulate(nums.begin(), nums.begin()+i, 0);
                right_sum[i] = accumulate(nums.begin()+i+1, nums.end(), 0);
            }
                                          
            if(left_sum[i] == right_sum[i]) return i;
        }
        
        return -1;
    }
};