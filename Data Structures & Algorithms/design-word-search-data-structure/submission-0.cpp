class WordDictionary {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() : isEnd(false) {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* current = root;

        for (char c : word) {
            int index = c - 'a';

            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }

            current = current->children[index];
        }

        current->isEnd = true;
    }
    
    bool search(string word) {

        return fnDFS(word,0, root);
    }

    private:
    bool fnDFS(string word, int index, TrieNode* node)
    {
            if (node == nullptr) {
                return false;
            }

            if (index == word.size()) {
                return node->isEnd;
            }
            if(word[index] == '.')
            {
                for(auto childNode: node->children)
                {
                    if(childNode && fnDFS(word, index + 1, childNode) )
                    {
                        return true;
                    }
                }

            }else
            {   int childIndex = word[index] - 'a';
                if(node->children[childIndex])
                {
                    return fnDFS(word, index + 1, node->children[childIndex]);
                }
            }
            return false;
    }
};
