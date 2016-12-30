class Solution {
public:
    int climbStairs(int n) {
        vector<int> f(n+2, -1);
        f[0] = 0;
        f[1] = 1;
        f[2] = 1;
        return fibb(n+1, f);
    }

    int fibb(int n, vector<int> &f)
        if(f[n] == -1){
            cout << "safdf" <<  endl;
            if(n%2 == 0){
                f[n] = (fibb(n/2-1, f)+fibb(n/2+1, f))*fibb(n/2, f);
                return f[n];
            }
            else{
                f[n] = fibb(n/2+1, f)*fibb(n/2+1, f) + fibb(n/2, f)*fibb(n/2, f);
                return f[n];
            }
        }
        else{
            return f[n];
        }
    }
};
