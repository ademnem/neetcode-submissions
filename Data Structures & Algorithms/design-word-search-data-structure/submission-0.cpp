struct TrieNode {
    TrieNode* children[26];
    bool endOfWord;
    TrieNode() : endOfWord(false) {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class WordDictionary {
    TrieNode* root;

    bool dfs(string word, TrieNode* p) {
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            switch (c) {
                case '.':
                    for (int j = 0; j < 26; ++j) {
                        if (p->children[j] && dfs(word.substr(i + 1), p->children[j]))
                            return true;
                    }
                    return false;
                    break;        
                default:
                    int index =  tolower(c) - 'a';
                    if (p->children[index])
                        p = p->children[index];
                    else
                        return false;
            }
        }
        if (p->endOfWord)
            return true;
        return false;
    }
public:
    WordDictionary() : root(new TrieNode()) {}
    
    void addWord(string word) {
        TrieNode* p = root;        
        for (char c : word) {
            int index = c - 'a';
            if (p->children[index]) {
                p = p->children[index];
            } else {
                p->children[index] = new TrieNode();
                p = p->children[index];
            }
        }
        p->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, root);
    }
};
