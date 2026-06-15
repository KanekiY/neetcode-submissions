class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //重要 return dfs(0,0,0, board,word ); 和a* 不一样，start是不一样的
        for (int y = 0; y < board.size(); y++) {
            for (int x = 0; x < board[y].size(); x++) {
                if (dfs(x, y, 0, board, word)) {
                    return true;
                }
            }
        }

    return false;
    }

    bool dfs(int x, int y, int stringIndex, vector<vector<char>>& board,  string& word)
    {
        if(y >= board.size() || y < 0) return false;
        if(x >= board[y].size() || x < 0) return false;
        
        if(stringIndex == word.size())
        {
            return false;
        }

        if(board[y][x] == word[stringIndex] )
        {
            if( stringIndex == word.size()-1)
            {
                return true;
            }
             stringIndex++;
        }else
        {
            return false; // 如果recursion stack overflow, 一般就是early out没有做好
        }
        char temp = board[y][x];// 重要 back track, first mark occupied
        board[y][x] = '#'; // mark visited
            if(dfs(x+1,y,stringIndex, board, word)) return true;
            if(dfs(x-1,y,stringIndex, board, word)) return true;
            if(dfs(x,y+1,stringIndex, board, word)) return true;
            if(dfs(x,y-1,stringIndex, board, word)) return true;
        board[y][x] = temp; // 重要 backtrack
        
        return false;
    }
};
