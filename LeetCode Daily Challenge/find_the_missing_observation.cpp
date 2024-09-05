class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int sum=0;
        for(auto it:rolls) sum+=it;

        int x=mean*(n+m)-sum;

        if(((6*n)<x) or (x<n)) return {};

        int distributeMean=x/n;
        int mod=x%n;
        vector<int>ans(n,distributeMean);
        for(int i=0;i<mod;i++){
            ans[i]+=1;
        }
        
        return ans;
    }
};