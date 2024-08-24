int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n=wt.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=W;j>=0;j--){
                int take=0;
                if(wt[i-1]<=j){
                    take=val[i-1]+dp[i-1][j-wt[i]];
                }
                int notake=dp[i-1][j];
                
                dp[i][j]=max(take,notake);
            }
        }
        int ans=0;
        for(int j=0;j<=W;j++){
            ans=max(ans,dp[n][j]);
        }
        return ans;
    }