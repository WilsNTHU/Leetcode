class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        heapSort(nums);
        vector<int>:: iterator it = nums.begin();
        advance(it, k-1);
        return *it;
    }
    
    void heapSort(vector<int>& nums){
        int n = nums.size();
        for(int i=n/2 - 1; i>=0; i--) minHeapify(nums, n, i);
        for(int i=n-1; i>0; i--){
            int temp = nums[0];
            nums[0] = nums[i];
            nums[i] = temp;
            minHeapify(nums, i, 0);
        } 
    }
    
    void minHeapify(vector<int>& nums, int n, int idx){
        int left = 2*idx + 1;
        int right = 2*idx + 2;
        int smallest = idx;
        if(left<n && nums[left]<nums[smallest]) smallest = left;
        if(right<n && nums[right]<nums[smallest]) smallest = right;
        
        if(smallest != idx){
            int temp = nums[idx];
            nums[idx] = nums[smallest];
            nums[smallest] = temp;
            minHeapify(nums, n, smallest);
        }
    }
};