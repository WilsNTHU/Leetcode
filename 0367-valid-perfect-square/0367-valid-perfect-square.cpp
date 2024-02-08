class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = INT_MAX;
        long long mid, result;
        
        while(left <= right){
            mid = left + (right - left)/2;
            result = mid * mid;
            if(result == num) return true;
            else if(result > num) right = mid - 1;
            else left = mid + 1;
        }
        
        return false;
    }
};