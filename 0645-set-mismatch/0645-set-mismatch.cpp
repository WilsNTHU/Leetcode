class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> mp(n+1, 0);
        vector<int> ans(2, -1);
        for(int i=0; i<n; i++){
            int num = nums[i];
            mp[num]++;
            if(mp[num] == 2) ans[0] = num;
        }
        
        for(int i=1; i<=n; i++)
            if(mp[i] == 0) ans[1] = i;
        
        return ans;
    }
};