class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n+1);

        int i2=1;
        int i3=1;
        int i5=1;
        dp[1]=1;

        for(int i=2;i<=n;i++){
            int i2UglyNum=dp[i2]*2;
            int i3UglyNum=dp[i3]*3;
            int i5UglyNum=dp[i5]*5;

            int curr=min({i2UglyNum,i3UglyNum,i5UglyNum});
            dp[i]=curr;
            
            if(curr==i2UglyNum) i2++;
            if(curr==i3UglyNum) i3++;
            if(curr==i5UglyNum) i5++;
        }
        return dp[n];
        
    }
};