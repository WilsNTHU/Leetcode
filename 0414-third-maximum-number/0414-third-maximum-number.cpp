class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        
        int len = nums.size();
        if(len<=2) return nums[0];
        else{
            int count = 1;
            for(int i=1; i<len; i++){
                if(nums[i] != nums[i-1]) count++;
                if(count == 3) return nums[i];
            }
            return nums[0];
        }

    }
};