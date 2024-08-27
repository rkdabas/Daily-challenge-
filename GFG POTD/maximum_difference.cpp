class Solution {
public:

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++){
            int u  = edges[i][0];
            int v  = edges[i][1];
            double wt = succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<int,double>>pq;
        vector<double>dist(n,0.0);
        pq.push({start_node,1});
        dist[start_node]=1;

        while(!pq.empty()){
            auto front=pq.top();
            pq.pop();
            int node=front.first;
            double weight=front.second;
            for(auto it:adj[node]){
                int adjNode=it.first;
                double adjWeight=it.second;
                if(adjWeight*weight > dist[adjWeight]){
                    dist[adjWeight]=adjWeight*weight;
                    pq.push({adjNode,dist[adjWeight]});
                }
            }
        }
        return dist[end_node];
    }
};