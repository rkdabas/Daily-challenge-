// using trie
struct TrieNode {
public:
    TrieNode* children[26];
    int sum;
    bool isEnd;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        sum = 0;
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;
    unordered_map<string, int> keyMap; // To store the original values of keys
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word, int currVal) {
        int prevVal = 0;
        // If the key already exists
        if (keyMap.find(word) != keyMap.end()) {
            prevVal = keyMap[word];
        }

        TrieNode* crawler = root;
        for (int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if (crawler->children[ind] == NULL) {
                crawler->children[ind] = new TrieNode();
            }
            crawler->sum += (currVal-prevVal); // Update the sum at each node by delta
            crawler = crawler->children[ind];
        }
        crawler->sum+=(currVal-prevVal);
        keyMap[word]=currVal;
    }

    int search(string word) {
        TrieNode* crawler = root;
        for (int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if (crawler->children[ind] == NULL) return 0;
            crawler = crawler->children[ind];
        }
        return crawler->sum;
    }
};

class MapSum {
public:
    Trie trie;
    
    MapSum() {}
    
    void insert(string key, int val) {
        trie.insert(key, val);
    }
    
    int sum(string prefix) {
        return trie.search(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key, val);
 * int param_2 = obj->sum(prefix);
 */
