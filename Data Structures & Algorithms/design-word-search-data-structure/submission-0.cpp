class WordDictionary {
   private:
    struct TrieNode {
        bool isEnd = false;
        TrieNode* children[26];
        TrieNode() {
            isEnd = false;
            for (auto& child : children) {
                child = nullptr;
            }
        };
    };

    TrieNode* root;

   public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (current->children[idx] == nullptr) {
                current->children[idx] = new TrieNode();
            }

            current = current->children[idx];
        }

        current->isEnd = true;
    }

    bool searchRecursively(string word, int j, TrieNode* croot) {
        TrieNode* current = croot;

        for (int i = j; i < word.length(); ++i) {
            char ch = word[i];
            int idx = ch - 'a';

            if (ch == '.') {
                for (TrieNode* child : current->children) {
                    if (child != nullptr && searchRecursively(word, i + 1, child)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (current->children[idx] == nullptr) {
                    return false;
                }
                current = current->children[idx];
            }
        }

        return current->isEnd;
    }
    bool search(string word) { return searchRecursively(word, 0, root); }
};
