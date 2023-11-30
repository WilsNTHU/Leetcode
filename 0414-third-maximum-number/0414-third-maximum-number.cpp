class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        set<int>:: reverse_iterator it = s.rbegin();
        if(s.size() <= 2) return *it;
        else {
            advance(it, 2);
            return *it;
        }
    }
};