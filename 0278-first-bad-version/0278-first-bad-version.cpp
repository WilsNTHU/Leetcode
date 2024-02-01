// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1, right=n, mid;
        int min_idx = 0;
        while(left <= right){
            mid = left + (right-left)/2;
            bool feedback = isBadVersion(mid);
            if(feedback){
                min_idx = mid;
                right = mid-1;
            }
            else left = mid+1;
        }
        
        return min_idx;
    }
};