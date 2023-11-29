class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(auto it: nums){
            if((it>=10 && it<100) || (it>=1000 && it<10000) || (it==100000))  
                count++;
        }
        
        return count;
    }
};