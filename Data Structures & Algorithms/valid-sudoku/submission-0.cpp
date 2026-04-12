class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; ++i) {
            if (!validRow(board, i) || !validCol(board, i) || !validBox(board, i))
                return false;
        }
        return true;
    }

    bool validRow(vector<vector<char>>& board, int row) {
        vector<int> count(9, 0);
        for (int i = 0; i < 9; ++i) {
            switch(board[row][i]) {
                case '.':
                    break;
                default:
                    count[board[row][i] - '1']++;
            }
        }

        for (int c : count)
            if (c > 1)
                return false;
        return true;
    }

    bool validCol(vector<vector<char>>& board, int col) {
        vector<int> count(9, 0);
        for (int i = 0; i < 9; ++i) {
            switch(board[i][col]) {
                case '.':
                    break;
                default:
                    count[board[i][col] - '1']++;
            }
        }

        for (int c : count)
            if (c > 1)
                return false;
        return true;
    }

    bool validBox(vector<vector<char>>& board, int box) {
        int row = (box / 3) * 3;
        int col = (box % 3) * 3;

        vector<int> count(9, 0);
        for (int i = 0; i < 9; ++i) {
            char c = board[row + i / 3][col + i % 3];
            switch(c) { 
                case '.':
                    break;
                default:
                    count[c - '1']++;
            }
        }

        for (int c : count)
            if (c > 1)
                return false;
        return true;
    }
};
