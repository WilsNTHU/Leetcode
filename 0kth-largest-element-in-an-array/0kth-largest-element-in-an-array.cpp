class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> heap;
        for(int i=0; i<k; i++) heap.push_back(nums[i]);
        for(int i=k/2-1; i>=0; i--) min_heapify(heap, i, k);
        
        for(int i=k; i<n; i++){
            if(nums[i] > heap[0]){
                heap[0] = nums[i];
                min_heapify(heap, 0, k);
            }
        }
        
        for(int i=k-1; i>0; i--){
            int temp = heap[i];
            heap[i] = heap[0];
            heap[0] = temp;
            min_heapify(heap, 0, i-1);
        }
        
        return heap[k-1];
    }
    
    void min_heapify(vector<int> &heap, int idx, int size){
        int left_child = 2*idx + 1;
        int right_child = 2*idx + 2;
        int largest = idx;
        if(left_child < size && heap[largest] > heap[left_child]) 
            largest = left_child;
        if(right_child < size && heap[largest] > heap[right_child]) 
            largest = right_child;
        if(largest != idx){
            int temp = heap[largest];
            heap[largest] = heap[idx];
            heap[idx] = temp;
            min_heapify(heap, largest, size);
        }
    }
    
};