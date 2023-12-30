class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> map;
        vector<int> result;
        
        for(int i=nums2.size()-1; i>=0; i--){
            while(!s.empty() && s.top()<nums2[i]) s.pop();
            
            if(s.empty()) map[nums2[i]] = -1;
            else map[nums2[i]] = s.top();
            
            s.push(nums2[i]);
        }
        
        for(auto it: nums1) result.push_back(map[it]);
        return result;
    }
};