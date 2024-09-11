   long long minCost(vector<long long>& arr) {
        int n=arr.size();
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(auto it:arr) pq.push(it);
        if(pq.size()==1) return 0;
        
        long long ans=0;
        while(pq.size()>1){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            
            long long sum=a+b;
            pq.push(sum);
            ans+=sum;
        }
        return ans;
    }