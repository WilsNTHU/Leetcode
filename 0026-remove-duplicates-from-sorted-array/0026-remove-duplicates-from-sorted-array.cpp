class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        int len = nums.size();
        
        if(len <= 1) return 1;
        else{
            for(int j=1; j<len; j++){
                if(nums[j] != nums[pos]){
                    pos++;
                    swap(nums[j], nums[pos]);
                }
            }
        }
        
        return pos+1;
    }
};