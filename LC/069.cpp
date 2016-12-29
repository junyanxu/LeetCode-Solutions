class Solution {
public:
    int mySqrt(int x) {
        double res=5;
        while(fabs(res*res - x) > 0.0001){
            res = res - (res*res-x)/(2*res);
        }
        return res;
    }
};
