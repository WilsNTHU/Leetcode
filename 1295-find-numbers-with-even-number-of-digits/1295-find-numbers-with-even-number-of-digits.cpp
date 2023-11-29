class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        int digits;
        int num;

        for(auto it: nums){
            num = it;
            digits = 1;
            
            while(num/10 != 0){
                digits ++;
                num /= 10;
            }
            
            if(!(digits & 1)) count++;
        }
        
        return count;
    }
};