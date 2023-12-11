class Solution {
public:
    // case observe
    // 1st row 0
    // 2nd row 01
    // 3rd row 0  1  1  0
    // 4th row 01 10 10 01
    
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;
        else if(n == 2) return (k==1) ? 0 : 1;
        else{
            if(k&1) return kthGrammar(n-1, k/2 + 1);
            else return !kthGrammar(n-1, k/2);
        }
    }
};