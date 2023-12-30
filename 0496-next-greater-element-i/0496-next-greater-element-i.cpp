class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> map;
        vector<int> result;
        
        for(auto it=nums2.rbegin(); it!=nums2.rend(); it++){
            while(!s.empty() && s.top()<(*it)) s.pop();
            
            if(s.empty()) map[*it] = -1;
            else map[*it] = s.top();
            
            s.push(*it);
        }
        
        for(auto it: nums1) result.push_back(map[it]);
        return result;
    }
};