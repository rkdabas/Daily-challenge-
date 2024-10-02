// using trie

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

    string startWith(string word){
        int n=word.size();
        string s;
        bool flag=false;
        TrieNode* crawler=root;
        for(int i=0;i<n;i++){
            int ind=word[i]-'a';
            if(crawler->children[ind]==NULL){
                break;
            }
            s.push_back(word[i]);
            crawler=crawler->children[ind];
            if(crawler->isEnd) return s;
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = sentence.size();
        Trie trie;
        
        for (auto it : dictionary) {
            trie.insert(it);
        }
        
        int i = 0;
        string ans = "";
        
        while (i < n) {
            int j = i;
            string s;
            
            while (j < n && sentence[j] != ' ') {
                s.push_back(sentence[j]);
                j++;
            }
            
            string x = trie.startWith(s);
            ans = ans + x + ' '; 
            i = j + 1;  
        }

        int k = ans.size() - 1;
        while (k >= 0 && ans[k] == ' ') ans.pop_back();
        
        return ans;
    }
};
