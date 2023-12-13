class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
    
    void heapSort(vector<int> &nums){
        int n = nums.size();
        for(int i=n/2 -1; i>=0; i--){
            maxHeapify(nums, n, i);
        }
        
        for(int i=n-1; i>0; i--){
            int temp = nums[i];
            nums[i] = nums[0];
            nums[0] = temp;
            maxHeapify(nums, i, 0);
        }
    }
    
    void maxHeapify(vector<int> &nums, int n, int idx){
        int left = 2*idx + 1;
        int right = 2*idx + 2;
        int largest = idx;
        if((left<n) && (nums[left]>nums[largest])) largest = left;
        if((right<n) && (nums[right]>nums[largest])) largest = right;
        
        if(largest != idx){
            int temp = nums[idx];
            nums[idx] = nums[largest];
            nums[largest] = temp;
            maxHeapify(nums, n, largest);
        }
    }
};