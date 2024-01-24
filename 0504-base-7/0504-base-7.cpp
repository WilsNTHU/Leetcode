class Solution {
public:
    string convertToBase7(int num) {
        string str = "";
        if(num == 0) return "0";
        
        bool neg = false;
        if(num < 0){
            neg = true;
            num = -num;
        }
        while(num != 0){
            str += to_string(num%7);
            num /= 7;
        }
        if(neg) str += '-';
        std::reverse(str.begin(), str.end());
        return str;
    }
};