class Solution {
public:
    string reverseWords(string s) {
        int l=0, r=0;
        int n = s.size();
        while(r < n){
            while(r<n &&s[r] != ' ') r++;
            if(l<r) reverse(s.begin()+l, s.begin()+r);
            l = r+1;
            r = l;
        }
        
        return s;
    }
};