// tabulation + trie

struct TrieNode{
    public:
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isEndOfWord=false;
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
        crawler->isEndOfWord=true;
    }
};

class Solution {
public:
Trie trie;
int solve(string s,int n,int i,vector<int>&dp){
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        int ans=1e9;
        TrieNode* curr=trie.root;
        for(int j=i;j<n;j++){
            int ind=s[j]-'a';
            if(curr->children[ind]==NULL) break;
            ans=min(ans,1+dp[j+1]);
            curr=curr->children[ind];
        }
        dp[i]=ans;
    }
    return dp[0];
}
    int minValidStrings(vector<string>& words, string target) {
        for(auto it:words){
            trie.insert(it);
        }
        int n=target.size();
        vector<int>dp(n+1,INT_MAX);
        int ans=solve(target,n,0,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};