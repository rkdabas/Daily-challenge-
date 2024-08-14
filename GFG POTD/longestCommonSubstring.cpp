// space optimised
int longestCommonSubstr(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        
        vector<int>prev(m+1,0);
        int ans=0;
        
        for(int i=1;i<=n;i++){
            vector<int>curr(m+1,0);
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    curr[j]=1+prev[j-1];
                    ans=max(ans,curr[j]);
                }
                else{
                    curr[j]=0;
                }
            }
            prev=curr;
        }
        return ans;
    }