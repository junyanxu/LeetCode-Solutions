class TrieNode{
public:
    TrieNode(){
        for(int i=0; i<26; i++){
            this->next[i] = NULL;
            this->isString = false;
        }
    }
    TrieNode* next[26];
    bool isString;
};


class WordDictionary {
public:

    WordDictionary(){
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* r = this->root;
        for(int i=0; i<word.length(); i++){
            if(!r->next[word[i]-'a'])
                r->next[word[i]-'a'] = new TrieNode();
            r = r->next[word[i]-'a'];
        }
        r->isString = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return recur_search(this->root, word, 0);
    }

    bool recur_search(TrieNode* curr, string word, int now){
        if(now == word.length())
            if(curr && curr->isString == true)
                return true;
            else
                return false;
        else
            if(!curr)
                return false;
            else{
                if(word[now] == '.'){
                    for(int i=0; i<26; i++){
                        if(recur_search(curr->next[i], word, now+1))
                            return true;
                    }
                    return false;
                }
                else{
                    return recur_search(curr->next[word[now]-'a'], word, now+1);
                }
            }
    }
private:
    TrieNode* root;
};
