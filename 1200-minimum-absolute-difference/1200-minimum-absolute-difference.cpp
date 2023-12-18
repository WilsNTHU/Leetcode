class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> result;
        heapSort(arr, n);
        int min_diff = INT_MAX;
        for(int i=1; i<n; i++) 
            min_diff = (min_diff < arr[i]-arr[i-1]) ? min_diff : arr[i]-arr[i-1];
        for(int i=1; i<n; i++){
            if(arr[i] - arr[i-1] == min_diff)
                result.push_back({arr[i-1], arr[i]});
        }
        
        return result;
    }
    
    void heapSort(vector<int> &arr, int n){
        for(int i=n/2-1; i>=0; i--) maxHeapify(arr, n, i);
        for(int i=n-1; i>0; i--){
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            maxHeapify(arr, i, 0);
        }
    }
    
    void maxHeapify(vector<int> &arr, int n, int index){
        int left = index*2 + 1;
        int right = index*2 + 2;
        int largest = index;
        if(left < n && arr[left]>arr[largest]) largest = left;
        if(right < n && arr[right]>arr[largest]) largest = right;
        if(largest != index){
            int temp = arr[largest];
            arr[largest] = arr[index];
            arr[index] = temp;
            maxHeapify(arr, n, largest);
        }
    }
};