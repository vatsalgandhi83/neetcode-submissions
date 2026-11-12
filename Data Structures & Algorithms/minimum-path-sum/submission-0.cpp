class Solution {
private: 
    int solve(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {

        if (m == 0 && n == 0) {
            return dp[0][0] = grid[0][0];
        }
        // cout << n << m << endl;
        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        int fromUp = INT_MAX, fromLeft = INT_MAX;

        if (n > 0) {
            fromUp = solve(n - 1, m, grid, dp);
        }
        if (m > 0) {
            fromLeft = solve(n, m - 1, grid, dp);
        }

        dp[n][m] = min(fromUp, fromLeft) + grid[n][m];
        // cout << "n: " << n << " m: " << m << " dp: " << dp[n][m] << endl;
        return dp[n][m];

    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // cout << "Size: " << n << m << endl;

        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(n - 1, m - 1, grid, dp);

        vector<int> prevRow(m);
        prevRow[0] = grid[0][0];

        for(int i = 1; i < m; i++) {
            prevRow[i] = prevRow[i - 1] + grid[0][i];
        }

        for(int i = 1; i < n; i++) {

            vector<int> temp(m);

            for(int j = 0; j < m; j++) {
                
                // cout << j << endl;
                if (j == 0) {
                    temp[0] = prevRow[0] + grid[i][j];
                } else {
                    temp[j] = min(temp[j - 1], prevRow[j]) + grid[i][j];
                }

            }

            prevRow = temp;

        }

        return prevRow[m - 1];
    }
};