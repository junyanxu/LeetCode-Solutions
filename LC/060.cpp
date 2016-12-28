class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        vector<int> fac(n, 1);
        vector<int> rank(n, 0);
        for(int i=1; i<fac.size(); i++){
            fac[i] = fac[i-1]*(i+1);
        }
        k--;
        for(int i=fac.size()-1; i>0; i--){
            rank[i] = (k)/fac[i-1];
            k = k%fac[i-1];
        }
        vector<char> table({'1', '2', '3', '4', '5', '6', '7', '8', '9'});
        for(int i=fac.size()-1; i>-1; i--){
            ret.push_back(table[rank[i]]);
            table.erase(table.begin()+rank[i]);
        }
        return ret;
    }
};
