class Solution {
private:
    int solve(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        
        if (m < 0 || n < 0 || obstacleGrid[m][n] == 1) {
            return 0;
        }

        if (n == 0 && m == 0) {
            return 1;
        }

        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        int fromUp = 0, fromLeft = 0;

        if (m > 0 && !obstacleGrid[m - 1][n]) {
            fromUp = solve(m - 1, n, obstacleGrid, dp);
        }

        if (n > 0 && !obstacleGrid[m][n - 1]) {
            fromLeft = solve(m, n - 1, obstacleGrid, dp);
        }

        dp[m][n] = fromUp + fromLeft;
        return dp[m][n];

    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, obstacleGrid, dp);
    }
};