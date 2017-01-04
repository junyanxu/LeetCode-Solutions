class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0){return;}
        pair<int, int> p = make_pair(-1, -1);
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    p = make_pair(i, j);
                }
            }
        }
        cout << p.first << " " << p.second << endl;
        if(p != make_pair(-1, -1) ){
            for(int i=0; i<matrix.size(); i++){
                if( matrix[i][p.second] == 0)
                    matrix[i][p.second] = 1;
                else
                    matrix[i][p.second] = 0;
            }
            for(int i=0; i<matrix[0].size(); i++){
                if(matrix[p.first][i] == 0)
                    matrix[p.first][i] = 1;
                else
                    matrix[p.first][i] = 0;
            }

            for(auto x: matrix){
                for(auto y:x){
                    cout << y << " ";
                }
                cout << endl;
            }
            cout << endl;
            for(int i=0; i<matrix.size(); i++){
                for(int j=0; j<matrix[0].size(); j++){
                    if(matrix[i][j] == 0 && i!= p.first && j!=p.second){
                            matrix[i][p.second] = 1;
                            matrix[p.first][j] = 1;
                    }
                }
            }
            for(auto x: matrix){
                for(auto y:x){
                    cout << y << " ";
                }
                cout << endl;
            }
            for(int i=0; i< matrix.size(); i++){
                if(matrix[i][p.second] != 0){
                    setRowZero(matrix, i);
                }
            }
            for(int i=0; i< matrix[0].size(); i++){
                if(matrix[p.first][i] != 0){
                    setColZero(matrix, i);
                }
            }
        }
        else{
            return;
        }
    }

    void setColZero(vector<vector<int>> & matrix, int col){
        for(int i=0; i<matrix.size(); i++){
            matrix[i][col] = 0;
        }
    }
    void setRowZero(vector<vector<int>>& matrix, int row){
        for(int i=0; i<matrix[0].size(); i++){
            matrix[row][i] = 0;
        }
    }
};
