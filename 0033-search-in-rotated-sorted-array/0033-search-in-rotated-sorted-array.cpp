class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1, mid;
        
        while(left <= right){
            mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;
            else if(nums[left] <= nums[mid]){  // left half is sorted
                if(nums[left]<=target && target<nums[mid])
                    right = mid-1; // target lies in the left half
                else left = mid+1;
            }
            else{ 
                if(nums[mid]<target && target<=nums[right])
                    left = mid+1;
                else right = mid-1;
            }
        }
        
        return -1;
    }
};