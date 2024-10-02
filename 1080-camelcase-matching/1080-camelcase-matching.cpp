// using trie
// insert pattern in trie and search for each query

struct TrieNode{
    public:
    TrieNode* children[58];
    bool isEnd;
    TrieNode(){
        for(int i=0;i<58;i++){
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
            int ind;
            if(isupper(word[i])) ind=word[i]-'A'+26;
            else ind=word[i]-'a';

            if(crawler->children[ind]==NULL){
                crawler->children[ind]=new TrieNode();
            }
            crawler=crawler->children[ind];
        }
        crawler->isEnd=true;
    }  
    
    bool search(string word){
        int n = word.size();
        TrieNode* crawler=root;
        for(int i=0;i<n;i++){
            int ind;
            if(isupper(word[i])) ind=word[i]-'A'+26;
            else ind=word[i]-'a';

            if(crawler->children[ind]!=NULL) crawler=crawler->children[ind];
            else{
                if(islower(word[i])) continue;
                else return false;
            }
        }
        if(crawler->isEnd==true) return true;
        return false;
        
    }
};

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans;
        Trie trie;
        trie.insert(pattern);
        for(auto it:queries){
            bool check=trie.search(it);
            ans.push_back(check);
        }
        return ans;
    }
};