class Solution {
public:
    int reverse(int y) {
        int x = abs(y);
        long long z = 0;
        while(x>0){
            z*=10;
            z+=x%10;
            x/=10;
        }
        if(abs(z) > INT_MAX)
            return 0;
        return y>0? z:-z;
    }
};
