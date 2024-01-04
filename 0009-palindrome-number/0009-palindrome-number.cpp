class Solution {
public:
    // stack solution
    // bool isPalindrome(int x) {
    //     stack<char> s;
    //     string str = to_string(x);
    //     int len = str.size(); bool odd = len%2;
    //     int i = 0;
    //     for(; i<len/2; i++) s.push(str[i]);
        
    //     if(odd) i++;
        
    //     for(; i<len; i++){
    //         if(str[i] == s.top()) s.pop();
    //         else return false;
    //     }
        
    //     if(s.empty()) return true;
    //     else return false;
    // }
    
    // math solution
    bool isPalindrome(int x) {
        if(x < 0) return false;

        int y = x;
        long long num = 0;
        while(y != 0){
            num = num*10 + y%10;
            y = y/10;
        }

        return (num == x);
    }
};