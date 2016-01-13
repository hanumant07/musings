#define vi vector<int>
#define vvi vector<vi>

class Solution {

public:
    static inline int getMin(int a, int b) {
        if (a == b == INT_MAX) return INT_MAX;
        return a < b ? a : b;
    }
    int coinChange(vector<int>& coins, int amount) {
        int rows = coins.size() + 1;
        int cols = amount + 1;
        int i, j;
        vvi sol(rows, vi(cols));
        for (i = 0; i < cols; i++)
            sol[0][i] = INT_MAX - 1;
        for (i = 0; i < rows; i++)
            sol[i][0] = 0;
        for (i = 1; i < rows; i++) {
            for (j = 1; j < cols; j++) {
                if (coins[i - 1] > j) {
                    sol[i][j] = sol[i - 1][j];
                   // cout << "for coin " << coins[i - 1] << " sol[" << i << "][" << j << "] is " << sol[i - 1][j] << endl;
                }
                else {
                    int res = getMin(1 + sol[i][j - coins[i - 1]], sol[i - 1][j]);
                    sol[i][j] = res != INT_MAX ? res : INT_MAX;
                   //cout << "for coin " << coins[i - 1] << " sol[" << i << "][" << j << "] is " << sol[i][j] << endl;
                }
            }
        }
        return sol[rows - 1][cols - 1] >= INT_MAX - 1? -1 : sol[rows - 1][cols - 1];
    }
};
