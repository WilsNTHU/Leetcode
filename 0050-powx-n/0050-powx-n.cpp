class Solution {
public:
    double myPow(double x, long long n) { 
        if(n == 0) return 1;
        else{
            if(n < 0){
                x = 1/x;
                n = -1 * n;
            } 
            if(n & 1) x = x * myPow(x, n-1);
            else x = myPow(x*x, n/2);
        }
        
        return x;
    }
};