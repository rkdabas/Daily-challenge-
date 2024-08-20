class Solution {
public:
// turn = 1 -> alice turn
// turn = 0 -> bob turn


int n;
int solve(vector<int>&piles,int turn,int ind, int m,vector<vector<vector<int>>>&dp){   // maximum stones alice can score
    if(ind>=n) return 0;
    if(dp[turn][ind][m]!=-1) return dp[turn][ind][m];

    int result;
    if(turn==1) result=-1;
    else result=INT_MAX;

    int stones=0;
    for(int x=1;x<=min(2*m,n-ind);x++){
        stones += piles[ind+x-1];
        if(turn==1){  // alice turn
            result=max(result,stones+solve(piles,0,ind+x,max(m,x),dp));
        }
        else{  // bob turn
            result=min(result,solve(piles,1,ind+x,max(m,x),dp));
        }
    }
    return dp[turn][ind][m]=result;
}
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n+1,vector<int>(2*n+1,-1)));
        return solve(piles,1,0,1,dp);
    }
};