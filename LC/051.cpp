class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> allSol;
        vector<string> sol;
        vector<int> col;
        solveNQ(n, 0, col, sol, allSol);
        return allSol;
    }

    void solveNQ(int n, int irow, vector<int> &col, vector<string> &sol, vector<vector<string>> &allSol) {
        if(irow==n) {
            allSol.push_back(sol);
            return;
        }

        for(int icol=0; icol<n; icol++) {
            if(validPos(col, irow, icol)) {
                string s(n,'.');
                s[icol] = 'Q';
                sol.push_back(s);
                col.push_back(icol);
                solveNQ(n, irow+1, col, sol, allSol);
                sol.pop_back();
                col.pop_back();
            }
        }
    }

    bool validPos(vector<int> &col, int irow, int icol) {
        if(irow<col.size()) return false;
        for(int i=0; i<col.size(); i++) {
            if(icol==col[i] || abs(irow-i)==abs(icol-col[i]))
                return false;
        }
        return true;
    }
};
