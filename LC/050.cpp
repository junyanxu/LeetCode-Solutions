class Solution {
public:
    double myPow(double x, int n) {
        bool isNeg = (n>0 ? true:false);
        n = abs(n);
        double res=1;
        double i=1;
        for(int i=0; i<32; i++){
            if((1<<i) & n){
                res*=x;
            }
            x*=x;
        }
        return isNeg? res: (i/res);
    }
};
