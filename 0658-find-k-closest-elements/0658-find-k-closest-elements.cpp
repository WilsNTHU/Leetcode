class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right-1, mid;
        while(k--){
            if(right>=n || (left>=0 && x-arr[left]<=arr[right]-x)) left--;
            else right++;
        }
        
        return vector<int>(arr.begin()+left+1, arr.begin()+right);
    }
};