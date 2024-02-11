class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0, right = n-1;
        
        while(left < right){
            int result = numbers[left] + numbers[right];
            if(result == target) return {left+1, right+1};
            else if(result > target) right--;
            else left++;
        }
        
        return {};
    }
};