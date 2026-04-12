class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                if (find_word(board, word, r, c, 0))
                    return true; 
            }
        }
        return false;
    }

    bool find_word(vector<vector<char>>& board, string word, int r, int c, int i) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
            return false;
        if (board[r][c] != word[i] || board[r][c] == '#')
            return false;
        
        if (i == word.length() - 1)
            return true;

        board[r][c] = '#';
        bool res = find_word(board, word, r + 1, c, i + 1) ||
                    find_word(board, word, r - 1, c, i + 1) ||
                    find_word(board, word, r, c + 1, i + 1) ||
                    find_word(board, word, r, c - 1, i + 1);
        board[r][c] = word[i];

        return res;
    }
};
