class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length() + 1;
        int m = text2.length() + 1;
        vector<vector<int>> res(n, vector<int>(m, 0));

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (text1[i - 1] == text2[j - 1])
                    res[i][j] = 1 + res[i - 1][j - 1];
                else
                    res[i][j] += max(res[i - 1][j], res[i][j - 1]);
            }
        }
        return res[n - 1][m - 1];
    }
};
