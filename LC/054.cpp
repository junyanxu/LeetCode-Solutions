class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(!matrix.size()){return ret;}
        int up=0; int down=(int)matrix.size()-1;
        int left=0; int right=(int)matrix[0].size()-1;
        while(up<down&&left<right){
            for(int i=0; i<right-left;i++){
                ret.push_back(matrix[up][left+i]);
            }
            for(int i=0; i<down-up; i++){
                ret.push_back(matrix[up+i][right]);
            }
            for(int i=0; i<right-left; i++){
                ret.push_back(matrix[down][right-i]);
            }
            for(int i=0; i<down-up; i++){
                ret.push_back(matrix[down-i][left]);
            }
            up++;left++;down--;right--;
        }
        if(left<right && up==down){
            for(int i=0; i<=right-left; i++){
                ret.push_back(matrix[up][left+i]);
            }
        }
        if(up<down && left==right){
            for(int i=0; i<=down-up; i++){
                ret.push_back(matrix[up+i][left]);
            }
        }
        if(up==down && left==right){
            ret.push_back(matrix[up][left]);
        }
        return ret;
    }
};
