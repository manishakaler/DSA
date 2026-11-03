class PrefixTree {
private:
    struct TrieNode {
        bool isEnd = false;
        // unordered_map<char,TrieNode*>children;
        TrieNode* children[26];
        TrieNode(){
           isEnd = false;
           for(auto& child: children){
                child = nullptr;
           }
        }
    };

    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;
        for(char c: word){
            int idx = c - 'a';
            if(current->children[idx] == nullptr){
                current->children[idx] = new TrieNode();
            }
            current = current->children[idx];
        }

        current->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;
        for(char ch: word){
            int idx = ch - 'a';
            if(current->children[idx] == nullptr){
                return false;
            }
            current = current->children[idx];
        }

        return current->isEnd == true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for(char ch: prefix){
            int idx = ch - 'a';
            if(current->children[idx] == nullptr){
                return false;
            }
            current = current->children[idx];
        }

        return true;
    }
};
