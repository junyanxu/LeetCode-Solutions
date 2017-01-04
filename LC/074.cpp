class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int down = (int)matrix.size()-1;
        if(matrix.size()==0){return false;}
        while(down > -1 && left < matrix[0].size()){
            if(matrix[down][left] == target)
                return true;
            else if(matrix[down][left] < target){
                left++;
            }
            else{
                down--;
            }
        }
        return false;
    }
};
