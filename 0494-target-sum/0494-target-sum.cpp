class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // (index, sum): count
        vector<unordered_map<int, int>> mp(n);
        return DFS(nums, n, 0, target, mp);
    }
    
    int DFS(vector<int>& nums, int n, int index, int sum, vector<unordered_map<int, int>>& mp){
        if(index == n) return (sum == 0);
        if(mp[index].find(sum) != mp[index].end()) return (mp[index])[sum];
        int count = 0;
        count += DFS(nums, n, index+1, sum-nums[index], mp);
        count += DFS(nums, n, index+1, sum+nums[index], mp);
        
        return (mp[index])[sum] = count;
    }
};