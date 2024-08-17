class Solution {
public:
// memoized way
long long solve(vector<vector<int>>&arr,int n,int m,int row,int col,vector<vector<long long>>&dp){
    if(row<0 or row>=n or col<0 or col>=m) return 0;
    if(dp[row][col]!=-1) return dp[row][col];

    long long ans=INT_MIN;
    for(int j=0;j<m;j++){
        long long cost=0;
        if(row!=0) cost= (arr[row][j] - abs(j-col)) + solve(arr,n,m,row+1,j,dp);
        else       cost= (arr[row][j]) + solve(arr,n,m,row+1,j,dp);
        ans=max(ans,cost);
    }
    return dp[row][col]=ans;
}
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int m=points[0].size();

        long long ans=INT_MIN;
        for(int j=0;j<m;j++){
            vector<vector<long long>>dp(n,vector<long long>(m,-1));
            ans=max(ans,solve(points,n,m,0,j,dp));
        }
        return ans;
    }
};





class Solution {
public:
// tabulative way -> chatgpt help
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();

        vector<vector<long long>> dp(n, vector<long long>(m, 0));

        // Base case: fill the last row with the points in the grid as they are
        for (int j = 0; j < m; j++) {
            dp[n-1][j] = points[n-1][j];
        }

        // Fill the DP table from the second last row to the top
        for (int i = n - 2; i >= 0; i--) {
            vector<long long> left(m), right(m);
            
            // Fill the left-to-right cumulative max for the current row
            left[0] = dp[i + 1][0];
            for (int j = 1; j < m; j++) {
                left[j] = max(left[j - 1] - 1, dp[i + 1][j]);
            }
            
            // Fill the right-to-left cumulative max for the current row
            right[m - 1] = dp[i + 1][m - 1];
            for (int j = m - 2; j >= 0; j--) {
                right[j] = max(right[j + 1] - 1, dp[i + 1][j]);
            }
            
            // Compute the dp values for the current row
            for (int j = 0; j < m; j++) {
                dp[i][j] = points[i][j] + max(left[j], right[j]);
            }
        }

        // Find the maximum value in the first row
        long long ans = LLONG_MIN;
        for (int j = 0; j < m; j++) {
            ans = max(ans, dp[0][j]);
        }

        return ans;
    }
};
