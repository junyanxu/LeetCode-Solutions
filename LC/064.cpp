class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0){
            return 0;
        }
        else{
            vector<vector<int>> dis(grid.size(), vector<int>(grid[0].size(), INT_MAX));
            dis[0][0] = grid[0][0];
            for(int i=1; i< grid.size(); i++){
                dis[i][0] = dis[i-1][0] + grid[i][0];
            }
            for(int i=1; i< grid[0].size(); i++){
                dis[0][i] = dis[0][i-1] + grid[0][i];
            }
            for(int i=1; i<grid.size(); i++){
                for(int j=1; j<grid[0].size(); j++){
                    dis[i][j] = min(dis[i-1][j], dis[i][j-1])+grid[i][j];
                }
            }
            return dis[dis.size()-1][dis[0].size()-1];
        }
    }
};
