class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size()-1);
        return nums;
    }
    
    void merge_sort(vector<int>& arr, int start, int end){
        if(start == end) return;
        int mid = start + (end-start)/2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, start, mid, end);
        return;
    }
    
    void merge(vector<int> &arr, int start, int mid, int end){
        vector<int> temp(end-start+1);
        int left=start, right=mid+1, cur=0;
        while(left<=mid && right<=end){
            if(arr[left] <= arr[right]) temp[cur++] = arr[left++];
            else temp[cur++] = arr[right++];
        }
        
        while(left<=mid) temp[cur++] = arr[left++];
        while(right<=end) temp[cur++] = arr[right++];
        
        int idx=0;
        while(start<=end) arr[start++] = temp[idx++];
            
        return;
    }
};