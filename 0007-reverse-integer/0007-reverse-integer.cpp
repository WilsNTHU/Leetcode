class Solution {
public:
    int reverse(int x) {
        bool flag = 0;
        long long y = x;
        if(y<0){
            flag = 1;
            y = -y;
        }
        
        
        long long num = 0;
        while(y != 0){
            num = num*10 + y%10;
            y /= 10;
        }
        
        if(num>INT_MAX || num<INT_MIN) return 0;
        else if(flag) return (-num);
        else return num;
    }
};