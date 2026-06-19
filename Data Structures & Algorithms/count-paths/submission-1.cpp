class Solution {
public:
    int uniquePaths(int m, int n) {
       // vector<vector<int>>&
        int row = m;
        int col = n;
        vector<vector<int>> memo(m, vector<int>(n,-1));
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        return dfs(visited, memo, 0,0,m,n);
    }

    int dfs(vector<vector<bool>>& visited, vector<vector<int>>& memo, int y, int x, int const row, int const col)
    {
        if( y >=row || x >= col) return 0;
        if (y ==row-1 && x == col-1) return 1;
        if(visited[y][x]) return 0;
        if(memo[y][x] != -1) return memo[y][x];
        visited[y][x] = true;
        int subResult = 0;
        subResult += dfs(visited,memo, y+1,x,row,col);
        subResult += dfs(visited,memo, y,x+1,row,col);
        memo[y][x] = subResult;
        visited[y][x] = false;
        return subResult;
    }
};
