class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int k=0;
            int j=0;
            while(k<s1.size() and j<s2.size()){
                if(s1[k]!=s2[j]){
                    adj[s1[k]-'a'].push_back(s2[j]-'a');
                    break;
                }
                k++;
                j++;
            }
        }
        
        vector<int>indegree(K,0);
        for(int i=0;i<K;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<K;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        string ans;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            ans.push_back(front+'a');
            
            for(auto it:adj[front]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;
        
    }
};