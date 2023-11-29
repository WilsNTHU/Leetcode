class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        int digits;
        string str;
        for(auto it: nums){
            digits = floor(log10(it)) + 1;
            if(!(digits & 1)) count++;
        }
        
        return count;
    }
};