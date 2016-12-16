class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp = vector<vector<bool>>(s.length()+1, vector<bool>(p.length()+1, true));
        for(int i=1; i<=s.length(); i++){
            dp[i][0] = false;
        }
        for(int i=1; i<=p.length(); i+= 2){
            if(p[i]!='*'){
                for(int j=i; j<=p.length(); j++)
                    dp[0][j] = false;
                break;
            }
        }
        for(int i = 1; i<=s.length(); i++){
            for(int j = 1; j<=p.length(); j++){
                if(p[j-1]!='*'){
                    dp[i][j] = dp[i-1][j-1] && (p[j-1] == '.' || s[i-1] == p[j-1]);
                }
                else{
                    dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (p[j-2] == '.'? true: p[j-2] == s[i-1]));
                }
            }
        }
        for(i: dp){
            for(j :i)
                cout << j << " ";
            cout << endl;
        }
        return dp[s.length()][p.length()];
    }
};
