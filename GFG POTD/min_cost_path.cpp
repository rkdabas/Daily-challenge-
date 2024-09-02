int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int>dist(n*m+1,INT_MAX);
        pq.push({grid[0][0],{0,0}});
        dist[1]=grid[0][0];
        
        int delRow[4]={-1,0,1,0};
        int delCol[4]={0,1,0,-1};
        
        while(!pq.empty()){
            auto front=pq.top();
            int dis=front.first;
            int row=front.second.first;
            int col=front.second.second;
            pq.pop();
            
            for(int i=0;i<4;i++){
                int nRow=row+delRow[i];
                int nCol=col+delCol[i];
                if((nRow>=0 and nRow<n and nCol>=0 and nCol<m)){
                    int nDis=grid[nRow][nCol];
                    int ind=nRow*m+nCol+1;
                    if(dis+nDis < dist[ind]){
                        dist[ind]=dis+nDis;
                        pq.push({dis+nDis,{nRow,nCol}});
                    }
                }
            }
        }
        return dist[n*m];
        
    }