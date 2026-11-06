class WordDictionary {
private:
    void addWordHelper(string& word, int pos) {

        if (word.size() == pos) {
            isEnd = true;
            return;
        }

        int index = word[pos] - 'a';

        if (next[index] == NULL) {
            next[index] = new WordDictionary();
        }

        next[index]->addWordHelper(word, pos + 1);

    }
    bool searchHelper(string& word, int pos) {

        if(word.size() == pos) {
            // if (word[pos - 1] == '.') {
            //     return true;
            // }
            return isEnd;
        }

        if (word[pos] == '.') {
            for(int i = 0; i < 26; i++) {
                if (next[i] != NULL) {
                    if (next[i]->searchHelper(word, pos+1)) {
                        return true;
                    }
                }
            }
            return false;
        }

        int index = word[pos] - 'a';

        if (next[index] == NULL) {
            return false;
        }

        return next[index]->searchHelper(word, pos + 1);

    }
public:
    bool isEnd;
    vector<WordDictionary*> next;
    WordDictionary() {
        this->isEnd = false;
        this->next = vector<WordDictionary*> (26, NULL);
    }
    
    void addWord(string word) {
        addWordHelper(word, 0);
    }
    
    bool search(string word) {
        return searchHelper(word, 0);
    }
};
