class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left=0;
        int right=matrix[0].size()-1;
        int up=0;
        int down =matrix.size()-1;
        int temp;
        while(up < down){
            for(int i=0; i<right-left; i++){
                temp = matrix[up][left+i];
                matrix[up][left+i] = matrix[down-i][left];
                matrix[down-i][left] = matrix[down][right-i];
                matrix[down][right-i] = matrix[up+i][right];
                matrix[up+i][right] = temp;
            }
            up++; down--; left++; right--;
        }
    }
};
