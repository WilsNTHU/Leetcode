class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max_num = -1;
        int idx;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > max_num){
                max_num = nums[i];
                idx = i;
            }
        }
        
        sort(nums.begin(), nums.end(), [](int &x, int &y){
            return x > y;
        });
        
        if(nums[0] >= (nums[1]*2)) return idx;
        else return -1;
    }
};