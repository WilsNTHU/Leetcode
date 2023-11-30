class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int len = arr.size();
        int max_num = -1;
        int temp;
        
        for(int i=len-1; i>=0; i--){
            temp = arr[i];
            arr[i] = max_num;
            max_num = max(arr[i], temp);
        }

        return arr;
    }
};