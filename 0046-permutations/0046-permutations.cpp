class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int size = nums.size();
        int flag;
        sort(nums.begin(), nums.end());
        
        do{
            flag = next_permutation(nums.begin(), nums.end());
            result.push_back(nums);
        }while(flag);
        
        return result;
    }
};