class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        else{
            if(n < 0){
                x = 1/x;
                n = abs(n);
            }
            if(n&1) return x * myPow(x, n-1);
            else return myPow(x*x, n/2);
        } 
    }
};