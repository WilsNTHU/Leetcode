class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> mp(n);
        vector<int> result;
        for(auto &x: nums) mp[x]++;
        
        for(int i=1; i<=n; i++){
            if(mp[i]==2)
                result.push_back(i);
        }
        
        for(int i=1; i<=n; i++){
            if(mp[i]==0)
                result.push_back(i);
        }
        
        if(result.size() == 2) return result;
        else result.push_back(n+1);
        
        return result;
    }
};