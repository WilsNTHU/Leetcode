class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        
        int cur = 0;
        for(auto it: nums){
            result.push_back(it + cur);
            cur += it;
        }
        
        return result;
    }
};