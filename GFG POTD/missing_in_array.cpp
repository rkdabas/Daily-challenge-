// Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {

        int m=arr.size();
        int a=0;
        for(int i=1;i<=n;i++) a=a^i;
        int b=0;
        for(auto it:arr) b=b^it;
        
        return a^b;
    }