class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        int cur_min = 0, min_sum = INT_MAX;
        int cur_max = 0, max_sum = INT_MIN;
        int total = 0;
        
        for(int num: nums){
            total += num;
            cur_min = min(cur_min+num, num);
            min_sum = min(min_sum, cur_min);
            
            cur_max = max(cur_max+num, num);
            max_sum = max(max_sum, cur_max);
        }
        
        if(total == min_sum) return max_sum; // case where all elements are negative
        else return (total-min_sum > max_sum) ? total-min_sum : max_sum;
        
    }
};