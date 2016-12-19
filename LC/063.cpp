class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if(!obstacleGrid.size()||obstacleGrid[0][0] == 1){return 0;}
        vector<int> dp(obstacleGrid[0].size(), 1);
        for(int i=1; i<obstacleGrid[0].size(); i++){dp[i] = (obstacleGrid[0][i]==1? 0:dp[i-1]);}
        for(int i=1; i<obstacleGrid.size(); i++){
            for(int j=0; j<obstacleGrid[0].size(); j++){
                if(j==0){dp[j]=(obstacleGrid[i][j]==1?0:dp[j]);}
                else{
                    dp[j] = (obstacleGrid[i][j]==1?0:dp[j]+dp[j-1]);
                }
            }
            for(auto x: dp){
                cout<< x << " ";
            }
            cout << endl;
        }
        return dp[obstacleGrid[0].size()-1];
    }
};
