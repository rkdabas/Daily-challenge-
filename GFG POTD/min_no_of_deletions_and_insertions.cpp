int minOperations(string str1, string str2) 
	{ 
	    int n1=str1.size();
	    int n2=str2.size();
	    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
	    dp[0][0]=0;
	    for(int i=1;i<=n1;i++){
	        dp[i][0]=i;
	    }
	    for(int j=1;j<=n2;j++){
	        dp[0][j]=j;
	    }
	    
	    for(int i=1;i<=n1;i++){
	        for(int j=1;j<=n2;j++){
	            if(str1[i-1]==str2[j-1]){
	                dp[i][j]=dp[i-1][j-1];
	            }
	            else{
	                dp[i][j]=min(1+dp[i][j-1],1+dp[i-1][j]);
	            }
	        }
	    }
	    return dp[n1][n2];
	    
	} 