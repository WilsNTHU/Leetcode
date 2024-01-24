class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        while(true){
            int idx = left + (right-left)/2;
            int new_idx = partition(nums, idx, left, right);
            if(new_idx == nums.size()-k) return nums[new_idx];
            else if(new_idx > nums.size()-k) right = new_idx - 1;
            else left = new_idx + 1;
        }
        
        return -1;
    }
    
    int partition(vector<int> &nums, int idx, int left, int right){
        int new_idx = left;
        int pivot = nums[idx];
        swap(nums[idx], nums[right]);
        for(int i=left; i<right; i++){
            if(nums[i] < pivot){
                swap(nums[i], nums[new_idx]);
                new_idx++;
            }
        }
        
        swap(nums[right], nums[new_idx]);
        return new_idx;
    }
    
};