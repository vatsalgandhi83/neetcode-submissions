class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> squares;

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.')
                    continue;
                
                //    0   1   2
                // 0  b1  b2  b3
                // 1  b4  b5  b6
                // 2  b7  b8  b9

                // b1 -> block 1 consisting of 9 squares

                pair<int, int> squareKey = {i/3, j/3};

                // check if the current number is already present
                // if count != 0, then number is present
                if (rows[i].count(board[i][j]) || cols[j].count(board[i][j]) || squares[squareKey].count(board[i][j]))
                    return false;

                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                squares[squareKey].insert(board[i][j]);

            }
        }
        return true;
    }
};
