class PrefixTree {
public:
    PrefixTree()
    {
        m_root = new TrieNode();
    }
    struct TrieNode 
    {
        TrieNode* children[26];
        bool m_isEnd;

        TrieNode() {
            m_isEnd = false;

            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* m_root;

    void insert(string word) {
        auto current = m_root;
        for(char c: word)
        {   if (current->children[c- 'a'] == nullptr)
            {
                current->children[c- 'a'] = new TrieNode();
            }
            
            current = current->children[c- 'a'];
        }
        current->m_isEnd = true;
    }
    
    bool search(string word) {
        auto current = m_root;
        for(char c: word)
        {
             if (current->children[c- 'a'] == nullptr) return false;
            current = current->children[c- 'a'];
        }
        return current->m_isEnd;
    }
    
    bool startsWith(string prefix) {
        auto current = m_root;
        for(char c: prefix)
        {
            if (current->children[c- 'a'] == nullptr) return false;
            current = current->children[c- 'a'];
        }
        return true;
    }
};
