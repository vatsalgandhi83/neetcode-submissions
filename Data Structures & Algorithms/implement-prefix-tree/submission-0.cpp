class PrefixTree {
private:
    void insertHelper(string& word, int pos) {
        if (pos == word.size()) {
            isEnd = true;
            return;
        }

        int index = word[pos] - 'a';

        if (next[index] == NULL) {
            next[index] = new PrefixTree();
        }

        next[index]->insertHelper(word, pos + 1);

    }
    bool searchHelper(string& word, int pos) {
        
        if (pos == word.size()) {
            return isEnd;
        }
        
        int index = word[pos] - 'a';

        if(next[index] == NULL) {
            return false;
        }

        return next[index]->searchHelper(word, pos + 1);

        return true;

    }
    bool startsWithHelper(string& prefix, int pos) {
        if (prefix.size() == pos){
            return true;
        }

        int index = prefix[pos] - 'a';

        if (next[index] == NULL) {
            return false;
        }

        return next[index]->startsWithHelper(prefix, pos + 1);
    }
public:
    bool isEnd;
    vector<PrefixTree*> next;
    PrefixTree() {
        this->isEnd = false;
        this->next = vector<PrefixTree*>(26, NULL);
    }
    
    void insert(string word) {

        insertHelper(word, 0);

        // if (word.empty()) {
        //     isEnd = true;
        //     return;
        // }

        // int index = word[0] - 97;

        // if (next[index] == nullptr) {
        //     next[index] = new PrefixTree();
        // }

        // next[index]->insert(word.substr(1));
    }
    
    bool search(string word) {
        return searchHelper(word, 0);
    }
    
    bool startsWith(string prefix) {
        return startsWithHelper(prefix, 0);
    }
};

/**
 * Your PrefixTree object will be instantiated and called as such:
 * PrefixTree* obj = new PrefixTree();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */