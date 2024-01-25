class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        
        vector<int> pos;
        pos.push_back(0);
        int count = 1;
        int prev = nums[0];
        freq[nums[0]]++;
        for(int i=1; i<n; i++){
            if(nums[i] == prev) count++;
            else{
                pos.push_back(pos.back()+count);
                count = 1;
                prev = nums[i];
            }
            
            freq[nums[i]]++;
        }
        
        int size = pos.size();
        if(size == 1) return nums[0] * freq[nums[0]];
        
        vector<int> dp(size, -1);
        dp[0] = nums[0] * (pos[1]-pos[0]);
        if(nums[pos[1]] == nums[pos[0]]+1) 
            dp[1] = max(dp[0], nums[pos[1]] * freq[nums[pos[1]]]);
        else dp[1] = dp[0] + (nums[pos[1]] * freq[nums[pos[1]]]);
        
        for(int i=2; i<size; i++){
            if(nums[pos[i]] == (nums[pos[i-1]] + 1)) 
                dp[i] = max(dp[i-1], dp[i-2]+ (nums[pos[i]] * freq[nums[pos[i]]]));
            else 
                dp[i] = max(dp[i-1], dp[i-2]) + (nums[pos[i]] * freq[nums[pos[i]]]);
        }
        
        return dp[size-1];
    }
};