class NumMatrix {
private:
    vector<vector<int>> prefixMatrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // vector<vector<int>> prefixMatrix(n, vector<int>(m,0));

        this->prefixMatrix.assign(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                prefixMatrix[i + 1][j + 1] = matrix[i][j] + prefixMatrix[i][j + 1] + prefixMatrix[i + 1][j] - prefixMatrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        row2++;
        col1++;
        col2++;
        return prefixMatrix[row2][col2] - prefixMatrix[row2][col1 - 1] - prefixMatrix[row1 - 1][col2] + prefixMatrix[row1 - 1][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */