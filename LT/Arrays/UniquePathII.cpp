#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 1;
        int rows = obstacleGrid.size() + 1;
        int cols = obstacleGrid[0].size() + 1;
        int i, j;
        vvi sol(rows, vi(cols, 1));

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (i - 1 == 0) { 
                    sol[i][j] = (!obstacleGrid[i - 1][j - 1] && sol[i][j - 1] != 0) ? 1 : 0;
                    continue;
                }
                if (j - 1 == 0) {
                    sol[i][j] = (!obstacleGrid[i - 1][j - 1] && sol[i - 1][j] != 0) ? 1 : 0;
                    continue;
                }
                if (!obstacleGrid[i - 1][j - 1]) {
                    sol[i][j] = (sol[i][j - 1] != 0 ? sol[i][j -1] : 0) +
                                (sol[i - 1][j] != 0 ? sol[i - 1][j] : 0);
                }
                else
                    sol[i][j] = 0;
            }      
        }
        return sol[rows - 1][cols - 1];
    }
};