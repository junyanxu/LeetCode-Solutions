class Solution {
public:
    int totalNQueens(int n) {
        vector<int> pos(n, 0);
        int num = 0;
        search(pos, num, 0, n);
        return num;
    }

    void search(vector<int>&pos, int&num, int icol, int n){
        if(icol == n-1){
            for(int i=0; i<n; i++){
                pos[icol] = i;
                if(checkValid(pos, icol))
                num++;
            }
        }
        else{
            for(int i=0; i<n; i++){
                pos[icol] = i;
                if(checkValid(pos, icol))
                    search(pos, num, icol+1, n);
            }
        }
    }

    bool checkValid(vector<int>pos, int icol){
        int row = pos[icol];
        for(int i=0; i<icol; i++){
            if(row == pos[i])
                return false;
        }
        for(int i=0; i<icol; i++){
            if(abs(pos[icol] - pos[i]) == abs(icol - i))
            return false;
        }
        return true;
    }
};
