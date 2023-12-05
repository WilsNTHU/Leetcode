class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int left = 0, right = len-1;
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                return vector<int>({left+1, right+1});
            }
            else if(sum < target) left++;
            else right--;
        }
        
        return vector<int>(-1);
    }
};