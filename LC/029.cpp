class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor) return dividend>=0 ? INT_MAX : INT_MIN;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX; //overflow problem

        bool isNeg = false;
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)) isNeg = true;
        unsigned long long dvd = abs((long long)dividend);
        unsigned long long dvs = abs((long long)divisor);
        unsigned long long dvs_original = dvs;
        int i = 0;
        int res = 0;
        while(dvs<<(i+1) <= dvd) i++;
        for(int x=i; x>-1; x--){
            if(dvd >= (dvs<<x)){
                res += (1<<x);
                dvd -= (dvs<<x);
            }
        }
        return isNeg ? 0-res : res;
    }
};
