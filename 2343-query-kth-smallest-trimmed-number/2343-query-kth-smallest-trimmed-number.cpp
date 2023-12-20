class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> result;
        int n = nums.size();
        for(auto &p: queries){
            vector<pair<string, int>> table;
            for(int i=0; i<n; i++){
                table.emplace_back(nums[i].substr(nums[i].size()-p[1], p[1]), i);
            }
            nth_element(table.begin(), table.begin() + p[0]-1, table.end());
            result.emplace_back(table[p[0]-1].second);
        }
        
        return result;
    }
    
};