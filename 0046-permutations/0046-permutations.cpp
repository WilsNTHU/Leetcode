class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        helper(result, nums, 0, nums.size());
        return result;
    }
    
    void helper(vector<vector<int>> &result, vector<int> &nums, int l, int r){
        if(l == r){
            result.push_back(nums);
            return;
        }
        else{
            for(int i=l; i<r; i++){
                swap(nums[l], nums[i]);
                helper(result, nums, l+1, r);
                swap(nums[l], nums[i]);
            }
        }
    }
};