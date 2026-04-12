struct TrieNode {
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
        endOfWord = false;
    }
};


class PrefixTree {
   TrieNode* root; 
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* p = root;

        for (char c : word) {
            int index = tolower(c) - 'a';        
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
        TrieNode* p = root;

        for (char c : word) {
            int index = tolower(c) - 'a';        
            if (p->children[index])
                p = p->children[index];
            else
                return false;
        }
        
        if (p->endOfWord)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (char c : prefix) {
            int index = tolower(c) - 'a';
            if (p->children[index]) 
                p = p->children[index];
            else   
                return false;
        }
        return true;
    }
};
