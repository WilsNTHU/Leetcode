class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_sum(n); // using prefix sum algorithm
        prefix_sum[0] = nums[0];
        
        int left_sum, right_sum;
        
        for(int i=1; i<=n-1; i++){
            prefix_sum[i] = nums[i] + prefix_sum[i-1];
        }
        for(int i=0; i<n; i++){
            if(i == 0) left_sum = 0;
            else left_sum = prefix_sum[i-1];
            
            if(i == n-1) right_sum = 0;
            else right_sum = prefix_sum[n-1] - prefix_sum[i];
            
            if(left_sum == right_sum) return i;
        }
        return -1;
    }
};