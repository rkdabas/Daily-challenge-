  void dfs(int node,vector<int>&vis,vector<int>adj[],int n){
      vis[node]=1;
      for(auto it:adj[node]){
          if(!vis[it]){
              dfs(it,vis,adj,n);
          }
      }
  }
    int isCircle(vector<string> &arr) {
        int n=arr.size();
        vector<int>adj[26];
        vector<int>indegree(26,0);
        vector<int>outdegree(26,0);
        
        for(int i=0;i<n;i++){
            string s=arr[i];
            int first=s[0]-'a';
            int second=s[s.size()-1]-'a';
            adj[first].push_back(second);
            
            indegree[second]++;
            outdegree[first]++;
        }
        
    
        for(int i=0;i<26;i++){
            if(indegree[i]!=outdegree[i]) return false;
        }
        // check if created directed graph has only 1 component or not
        vector<int>vis(26,0);
        dfs(arr[0][0]-'a',vis,adj,n);
        
        for(int i=0;i<26;i++){
            if(indegree[i]!=0 and outdegree[i]!=0 and !vis[i]){
                return false;
            }
        }
        return true;
    }