class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* next[26];
    bool isString;
    TrieNode() {
        for(int i=0; i<26; i++){
            next[i]=NULL;
        }
        isString = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* r = root;
        for(int i=0; i<word.length(); i++){
            if(!r->next[word[i]-'a'])
                r->next[word[i]-'a'] = new TrieNode();
            r = r->next[word[i]-'a'];
        }
        r->isString = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* r = root;
        for(int i=0; i<word.length(); i++){
            if(!r->next[word[i]-'a'])
                return false;
            r = r->next[word[i]-'a'];
        }
        if(r->isString)
            return true;
        else
            return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* r = root;
        for(int i=0; i<prefix.length(); i++){
            if(!r->next[prefix[i]-'a'])
                return false;
            r = r->next[prefix[i]-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};
