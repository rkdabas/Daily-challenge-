class Solution
{
    public:
    // memoized way
    int solve(int n,int x,int y,int z,vector<int>&dp){
        if(n==0) return 0;
        if(n<0) return INT_MIN;
        if(dp[n]!=-1) return dp[n];
        
        int op1=solve(n-x,x,y,z,dp);
        int op2=solve(n-y,x,y,z,dp);
        int op3=solve(n-z,x,y,z,dp);
        
        int maxCut=max({op1,op2,op3});
        if(maxCut==INT_MIN) return dp[n]=INT_MIN;
        else return dp[n]=1+maxCut;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+max({x,y,z})+1,-1);
        int ans=solve(n,x,y,z,dp);
        if(ans==INT_MIN) return 0;
        return ans;
    }
};