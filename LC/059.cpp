class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(vector<vector<int>>(n, vector<int>(n, 0)));
        int mid = (n + 1)/2;
        int down;
        int right;
        int count = 0;
        for(int i=0; i<mid; i++){
            down = n-1-i;
            right = n-1-i;
            for(int j=i; j<=right; j++){
                count ++;
                res[i][j] = count;
            }
            for(int j=i+1; j<=down; j++){
                count++;
                res[j][right] = count;
            }
            for(int j = right-1; j>=i; j--){
                count++;
                res[down][j] = count;
            }
            for(int j=down-1; j>=i+1; j--){
                count ++;
                res[j][i] = count;
            }
        }
        return res;
    }
};
