class Solution {
public:
    int BinarySearch(vector<int>& nums, int left, int right, int target){
        
        if(left <= right){
            int mid = left + (right-left)/2;
            
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) left = mid+1;
            else right = mid-1;
            
            return BinarySearch(nums, left, right, target);
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        return BinarySearch(nums, 0, nums.size()-1, target);
    }
};