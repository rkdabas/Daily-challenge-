class Solution{
	public:
	
		int nthStair(int n){
		    vector<int>dp(n+1);
		    dp[0]=1;
		    dp[1]=1;
		    for(int i=2;i<=n;i++){
		        dp[i]=dp[i-1]+dp[i-2];
		        if(i>=3) dp[i]-=dp[i-3];
		    }
		    return dp[n];
		    
		    
		}
};