class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max_count = 0;
        int len = nums.size();
        for(int i=0; i<len; i++){
            if(nums[i]==0){
                max_count = max(count, max_count);
                count = 0;
            }
            else{
                count++;
                if(i == len-1) max_count = max(count, max_count);
            }
        }
        
        return max_count;
    }
};