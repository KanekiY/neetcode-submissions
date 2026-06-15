class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        string word;// 相对于bool的isEnd,我们偷懒直接存word

        TrieNode() {
            word = "";
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root = new TrieNode();

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string& word : words) {
            insert(word);
        }

        vector<string> result;

        int rows = board.size();
        int cols = board[0].size();

        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                dfs(board, x, y, root, result);
            }
        }

        return result;
    }

private:
    void insert(const string& word) {
        TrieNode* current = root;

        for (char c : word) {
            int index = c - 'a';

            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }

            current = current->children[index];
        }

        current->word = word;
    }

    void dfs(
        vector<vector<char>>& board,
        int x,
        int y,
        TrieNode* node,
        vector<string>& result
    ) {
        if (y < 0 || y >= board.size()) return;
        if (x < 0 || x >= board[y].size()) return;

        char c = board[y][x];

        if (c == '#') return;

        int index = c - 'a';

        if (node->children[index] == nullptr) {
            return;
        }

        node = node->children[index];

        if (node->word != "") {
            result.push_back(node->word);

            // 防止重复加入同一个 word//也可以查重，但是不是好办法
            node->word = "";
        }

        board[y][x] = '#';

        dfs(board, x + 1, y, node, result);
        dfs(board, x - 1, y, node, result);
        dfs(board, x, y + 1, node, result);
        dfs(board, x, y - 1, node, result);

        board[y][x] = c;
    }
};
