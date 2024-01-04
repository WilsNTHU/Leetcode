class Solution {
public:
    int reverse(int x) {
        bool flag = (x<0) ? true : false;
        string str = to_string(x);
        if(flag) str = str.substr(1, str.size()-1);
        std:: reverse(str.begin(), str.end());
        
        int len = str.size();
        if(len == 10 && !flag && str.compare(to_string(INT_MAX))>0) return 0;
        else if(len == 10 && flag && str.compare("2147483648")>0) return 0;
        else if(flag) return (-1) * (stoi(str));
        else return stoi(str);
    }
};