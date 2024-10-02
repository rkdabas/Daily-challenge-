struct TrieNode{
    public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isEnd=false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
    void insert(string word){
        TrieNode* crawler=root;
        for(int i=0;i<word.size();i++){
            int ind=word[i]-'a';
            if(crawler->children[ind]==NULL){
                crawler->children[ind]=new TrieNode();
            }
            crawler=crawler->children[ind];
        }
        crawler->isEnd=true;
    }

    bool check(string word){
        TrieNode *crawler=root;
        for(int i=0;i<word.size();i++){
            int ind=word[i]-'a';
            if(crawler->children[ind]==NULL) return false;
            crawler=crawler->children[ind];
        }
        if(crawler->isEnd == true) return true;
        return false;
    }
};

class MagicDictionary {
public:
Trie trie;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto it:dictionary){
            trie.insert(it);
        }
    }
    
    bool search(string searchWord) {
        int n=searchWord.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                char curr=searchWord[i];
                if(curr==j+'a') continue;
                searchWord[i]=(j+'a');
                if(trie.check(searchWord)==true) return true;
                searchWord[i]=curr;
            }
        }
        return false;
        
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */