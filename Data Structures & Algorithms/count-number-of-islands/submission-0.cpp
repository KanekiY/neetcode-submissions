class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (grid[r][c] != '1')
            return;

        grid[r][c] = '0'; // 标记为已访问，也可以理解为“淹掉”

        int dx[4] = { -1,1,0,0};
		int dy[4] = { 0,0,1,-1 };

		for (int i =0; i<4;i++) 
		{   
            int nextR = r + dy[i];
            int nextC = c + dx[i];
            if (nextR < 0 || nextC < 0 || nextR >= rows || nextC >= cols) continue;
            if (grid[nextR][nextC] != '1') continue;
            
            dfs(grid,nextR,nextC);
		}
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '1') {
                    ++count;
                    dfs(grid, r, c);
                }
            }
        }

        return count;
    }
};
