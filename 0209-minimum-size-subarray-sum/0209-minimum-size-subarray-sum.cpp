class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0, sum=0;
        int n = nums.size();
        int len = n+2; // impossible case
        
        while(j<n){
            sum += nums[j];
            while(sum >= target){
                len = (len < (j-i+1)) ? len : j-i+1;
                sum -= nums[i];
                i++;
            }
            j++;
        }
        
        if(len == n+2) return 0;
        else return len;
    }
};