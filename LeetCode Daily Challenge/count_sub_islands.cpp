class Solution {
public:

// using dfs

bool flag;
vector<vector<int>>vis;
void solve(vector<vector<int>>&arr1,vector<vector<int>>&arr2,int n,int m,int row,int col){
    if(row<0 or row>=n or col<0 or col>=m or arr2[row][col]==0 or vis[row][col]==1) return;

    vis[row][col]=1;
    if(arr1[row][col]==0) flag=false;

    solve(arr1,arr2,n,m,row,col-1);
    solve(arr1,arr2,n,m,row,col+1);
    solve(arr1,arr2,n,m,row-1,col);
    solve(arr1,arr2,n,m,row+1,col);
}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        vis=vector<vector<int>>(n,vector<int>(m,0));

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 and !vis[i][j]){
                    flag=true;
                    solve(grid1,grid2,n,m,i,j);
                    if(flag==true) ans++;
                }
            }
        }
        return ans;
    }
};