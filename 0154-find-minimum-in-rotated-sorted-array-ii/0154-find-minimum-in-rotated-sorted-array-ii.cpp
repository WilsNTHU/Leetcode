class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1, mid;
        
        if(nums[left] < nums[right]) return nums[left];
        
        while(left < right){
            mid = left + (right - left)/2;
            if(nums[mid] == nums[right]) right--;
            else if(nums[mid] > nums[right]){ 
                left = mid + 1;
            }
            else{ // sorted
                right = mid;
            }
        }
        
        return nums[left];
    }
};

