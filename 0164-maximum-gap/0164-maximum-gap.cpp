class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // using Pigeonhole sort to achieve linear time complexity
        int n = nums.size();
        if(n < 2) return 0;
        else{
            int max = *max_element(nums.begin(), nums.end());
            int min = *min_element(nums.begin(), nums.end());
            if(max == min) return 0;
            
            double k = (double) (max-min) / n;
            
            vector<int> min_arr(n, INT_MAX);
            vector<int> max_arr(n, INT_MIN);
            for(auto &&it: nums){
                size_t index = (it-min) / k;
                if(index == n) index = n-1;
                if(it < min_arr[index]) min_arr[index] = it;
                if(it > max_arr[index]) max_arr[index] = it;
            }
            
            // gap = min_arr[i+1] - max_arr[i]
            int gap = 0, prev_max_gap = max_arr[0];
            for(int i=0; i<n-1; i++){
                if(min_arr[i+1] == INT_MAX) continue;
                if(gap < min_arr[i+1] - prev_max_gap) 
                    gap = min_arr[i+1] - prev_max_gap;
                prev_max_gap = max_arr[i+1];
            }
            
            return gap;
        }
        
    }
};