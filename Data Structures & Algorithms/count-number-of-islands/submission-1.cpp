class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                num += dfs(grid, r, c);
            }
        }           
        return num;
    }

    int dfs(vector<vector<char>>& grid, int r, int c) {
        if (r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0')
            return 0; 
        
        grid[r][c] = '0';
        dfs(grid, r + 1, c); 
        dfs(grid, r - 1, c); 
        dfs(grid, r, c + 1); 
        dfs(grid, r, c - 1); 
        return 1;
    }
};
