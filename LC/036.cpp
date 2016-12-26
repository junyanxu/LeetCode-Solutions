class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0};
        int col[9] = {0};
        int small[9] = {0};
        char temp;
        for(int i=0; i<9; i++)
        {
            memset(row, 0, sizeof(row));
            for(int j=0; j<9; j++)
            {
                temp = board[i][j];
                if(temp != '.')
                {
                    if(row[temp - '1'] == 1)
                    {
                        return false;
                    }
                    else
                    {
                        row[temp - '1']++;
                    }
                }
            }
        }
        for(int i=0; i<9; i++)
        {
            memset(col, 0, sizeof(col));
            for(int j=0; j<9; j++)
            {
                temp = board[j][i];
                if(temp != '.')
                {
                    if(col[temp - '1'] == 1)
                    {
                        return false;
                    }
                    else
                    {
                        col[temp - '1']++;
                    }
                }
            }
        }
        for(int i = 0; i<9; i=i+3)
        {
            for(int j = 0; j<9; j=j+3)
            {
                memset(small, 0, sizeof(small));
                for(int k = 0; k<9; k++)
                {
                    temp = board[i+k/3][j+k%3];
                    if(temp != '.')
                    {
                        if(small[temp - '1'] == 1)
                        {
                            return false;
                        }
                        else
                        {
                            small[temp - '1']++;
                        }
                    }
                }
                for (int x = 0; x<9; x++)
                {
                    cout << small[x] << " ";
                }
                cout << endl;
            }
        }
        return true;
    }
};
