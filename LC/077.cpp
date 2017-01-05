class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        dfs(res, vector<int>(), 1, n, k);
        return res;
    }

    void dfs(vector<vector<int>> &res, vector<int>curr, int start, int n, int k){
        if(curr.size()==k){
            cout << endl;
            res.push_back(curr);
        }
        else{
            for(int i=start; i<=n; i++){
                vector<int> temp = curr;
                temp.push_back(i);
                dfs(res, temp, i+1, n, k);
            }
        }
    }

};
