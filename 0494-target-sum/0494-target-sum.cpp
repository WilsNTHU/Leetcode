class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return DFS(nums, nums.size(), target, 0, 0);
    }
    
    int DFS(vector<int>& nums, int n, int target, int index, int sum){
        if(index == n) return (sum == target) ? 1 : 0;
        int count = 0;
        count += DFS(nums, n, target, index+1, sum+nums[index]);
        count += DFS(nums, n, target, index+1, sum-nums[index]);
        
        return count;
    }
};