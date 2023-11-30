class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int len = nums.size();
        int i=0, j=len-1;
        
        while(i < j){
            while(!(nums[i] & 1) && (i<j)) i++; // i points to parity integer
            while((nums[j]&1) && (i<j)) j--; // j points to even integer
            swap(nums[i], nums[j]);
            i++, j--;
        }
        
        return nums;
    }
};