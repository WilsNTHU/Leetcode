/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0, right = 10000, mid;
        int num;
        
        while(left <= right){
            mid = left + (right-left)/2;
            
            num = reader.get(mid);
            if(num == target) return mid;
            else if(num == INT_MAX || num > target) right = mid-1;
            else left = mid + 1;
        }
        
        return -1;
    }
};