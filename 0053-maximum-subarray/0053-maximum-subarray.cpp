class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int global_max = nums[0];
        int cur_max = nums[0];
        int end_index = 0;
        
        for(int i=1; i < nums.size(); i++){
            cur_max = max(nums[i], cur_max + nums[i]);

            if(cur_max > global_max){
                global_max = cur_max;
                end_index = i;
            }
        }

        return global_max;
    }
};