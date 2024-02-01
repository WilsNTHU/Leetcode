class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> arr;
        int prev;
        
        for(int i=0; i<nums.size()/3; i++){
            vector<int> temp;
            prev = nums[i*3];
            for(int j=0; j<3; j++){
                temp.push_back(nums[i*3 + j]);
                if(nums[i*3 + j]-prev > k) return {};
            }
            arr.push_back(temp);
        }
            
        
        return arr;
    }
};