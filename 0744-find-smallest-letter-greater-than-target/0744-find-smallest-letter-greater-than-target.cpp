class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int left = 0, right = n-1, mid;
        int ans = -1;
        while(left <= right){
            mid = left + (right - left)/2;
            if(letters[mid] > target){
                right = mid - 1;
                ans = letters[mid];
            } 
            else left = mid + 1;
        }
        
        if(ans == -1) return letters[0];
        else return ans;
    }
};