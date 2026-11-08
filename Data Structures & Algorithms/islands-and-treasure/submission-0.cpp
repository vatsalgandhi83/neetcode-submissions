class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int level = 0;
        while(!q.empty()) {
            int len = q.size();
            level++;
            for(int i = 0; i < len; i++) {
                int currI = q.front().first;
                int currJ = q.front().second;
                q.pop();

                for(auto dir : dirs) {
                    int newI = currI + dir.first;
                    int newJ = currJ + dir.second;

                    if(newI >= 0 && newJ >= 0 && newI < n && newJ < m && grid[newI][newJ] == INT_MAX) {
                        grid[newI][newJ] = level;
                        q.push({newI, newJ});
                    }

                }


            }

        }

    }
};
