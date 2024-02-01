/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        int mid;
        while(left <= right){
            mid = left + (right - left)/2;
            int feedback = guess(mid);
            if(feedback == 0) return mid;
            else if(feedback == 1) left = mid+1;
            else right = mid-1;
        }
        
        return -1;
    }
};