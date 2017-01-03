class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[] ={1,  1,  1,  0, 0, -1, -1, -1};
        int dy[] ={-1, 0,  1, -1, 1, -1,  0,  1};
        int live;
        int dead;
        for(int i=0; i<board.size(); i++){
            for(int j =0; j<board[0].size(); j++){
                live = 0; dead=0;
                for(int k=0; k<8; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x>-1 && y>-1 && x<board.size() && y<board[0].size()){
                        if(board[x][y] == 1 || board[x][y] == 2 || board[x][y] == 3)
                            live++;
                        else
                            dead++;
                    }
                }
                if(board[i][j]){
                    if(live < 2 || live > 3)
                        board[i][j] = 2;
                    if(live == 2 || live == 3)
                        board[i][j] = 3;
                }
                else{
                    if(live==3)
                        board[i][j] = 5;
                }
            }
        }
        for(int i=0; i< board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                board[i][j] = board[i][j]%2;
            }
        }
    }
};
