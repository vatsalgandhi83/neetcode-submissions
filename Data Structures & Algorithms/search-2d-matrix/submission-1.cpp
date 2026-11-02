class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0)
            return false;
        int cols = matrix[0].size();

        int left = 0, right = (rows*cols) - 1;

        while (left <= right) {
            int mid = (left + right)/2;
            int row = mid / cols;
            int col = mid % cols;
            if(target == matrix[row][col]) {
                return true;
            } else if(target < matrix[row][col]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};
