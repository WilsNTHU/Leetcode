class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        int t = k % len;
        reverse(nums.begin(), nums.begin() + (len-t));
        reverse(nums.begin() + (len-t), nums.end());
        reverse(nums.begin(), nums.end());
    }
};