
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        bfs(res, 0, n);
        return res;
    }

    void bfs(vector<int> &res, int now, int n){
            if(now!=0)
                res.push_back(now);
            for(int i=0; i<10; i++){
                if(10*now+i<= n && 10*now+i!=0)
                    bfs(res, 10*now+i, n);
        }
    }
};
