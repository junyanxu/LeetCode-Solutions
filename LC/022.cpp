class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", 0, n);
        return res;
    }

    void dfs(vector<string> &v, string curr, int numOfLeft, int n){
        if(curr.length()==2*n){
            v.push_back(curr);
        }
        else{
            int numOfRight = curr.length()-numOfLeft;
            string temp = curr;
            if(numOfRight < numOfLeft){
                temp.push_back(')');
                dfs(v, temp, numOfLeft, n);
            }
            if(numOfLeft < n){
                temp = curr;
                temp.push_back('(');
                dfs(v, temp, numOfLeft+1, n);
            }
        }
    }
};
