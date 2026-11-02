class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0)
            return false;
        int cols = matrix[0].size();

        int top = 0, bottom = rows - 1;

        // First binary search to find the correct row
        while (top < bottom) {
            int mid = (top + bottom) / 2;
            if (target < matrix[mid][0]) {
                bottom = mid - 1;
            } else if (target > matrix[mid][cols - 1]) {
                top = mid + 1;
            } else {
                top = bottom = mid;
            }
        }

        int row = top;
        int left = 0, right = cols - 1;

        // Second binary search in that row
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};
