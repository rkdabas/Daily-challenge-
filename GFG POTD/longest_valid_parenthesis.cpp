 int maxLength(string str) {
        int n=str.size();
        vector<int>dp(n);
        stack<int>s;
        for(int i=0;i<n;i++){
            if(str[i]=='(') s.push(i);
            else{
                if(s.empty()) dp[i]=0;
                else{
                    int ind=s.top();
                    s.pop();
                    dp[i]=1;
                    dp[ind]=1;
                }
            }
        }
        
        while(!s.empty()){
            int ind=s.top();
            s.pop();
            dp[ind]=0;
        }
        
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            while(j<n and dp[j]==1) j++;
            ans=max(ans,j-i);
            i=j+1;
            j++;
        }
        ans=max(ans,j-i);
        return ans;
    }