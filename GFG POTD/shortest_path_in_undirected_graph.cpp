class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        vector<pair<int,int>>adj[N];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back({1,v});
            adj[v].push_back({1,u});
        }
        vector<int>dist(N,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[src]=0;
        pq.push({0,src});
        
        while(!pq.empty()){
            auto front=pq.top();
            pq.pop();
            int node=front.second;
            int dis=front.first;
            for(auto it:adj[node]){
                int adjNode=it.second;
                int adjWeight=it.first;
                if(dis+adjWeight < dist[adjNode]){
                    dist[adjNode]=dis+adjWeight;
                    pq.push({dis+adjWeight,adjNode});
                }
            }
        }
        for(int i=0;i<dist.size();i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        return dist;
    }
};