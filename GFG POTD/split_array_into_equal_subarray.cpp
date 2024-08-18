   bool canSplit(vector<int>& arr) {
        int n=arr.size();
        vector<int>v1(n,0);
        v1[0]=arr[0];
        for(int i=1;i<n;i++){
            v1[i]=v1[i-1]+arr[i];
        }
        
        vector<int>v2(n,0);
        v2[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            v2[i]=v2[i+1]+arr[i];
        }
        
        int i=0;
        int j=1;
        while(j<n){
            if(v1[i]==v2[j]) return true;
            i++;
            j++;
        }
        return false;
    }