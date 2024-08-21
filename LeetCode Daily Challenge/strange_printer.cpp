class Solution {
public:
// using partition dp
int solve(string &s,int n,int l,int r,vector<vector<int>>&dp){
    if(l==r) return 1;
    if(l>r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];

    int i=l+1;
    while(i<=r and s[i]==s[l]){
        i++;
    }
    if(i==r+1) return 1;
    int res1=1+solve(s,n,i,r,dp);

    int res2=INT_MAX;
    for(int j=i;j<=r;j++){
        if(s[j]==s[l]){
            int ans=solve(s,n,i,j-1,dp) + solve(s,n,j,r,dp);
            res2=min(res2,ans);
        }
    }
    return dp[l][r]=min(res1,res2);
}
    int strangePrinter(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(s,n,0,n-1,dp);

    }
};