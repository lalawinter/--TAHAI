class Tries {
private:
    bool flag = false;
    Tries* next[26] = {nullptr};
public:
    Tries {};

    void insert(string& word) {
        Tries* node = this;
        for(int i = 0; i < word.size(); i++) {
            char c = word[i];
            if(node->next[c-'a'] == nullptr) {
                node->next[c-'a'] = new Tries();
            }
            node = node->next[c-'a'];
        }
        node->flag = true;
    }

    bool search(string& word) {
        Tries* node = this;
        for(int i = 0; i < word.size(); i++) {
            char c = word[i];
            if(node->next[c-'a' == nullptr]) return false;
            node = node->next[c-'a'];
        }
        return node->flag;
    }

    bool startWith(string& prefix) {
        Tries* node = this;
        for(int i = 0; i < prefix.size(); i++) {
            char c = prefix[i];
            if(node->next[c-'a'] == nullptr) return false;
            node = node->next[c-'a'];
        }
        return true;
    }
}