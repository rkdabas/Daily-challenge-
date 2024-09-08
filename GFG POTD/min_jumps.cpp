 int minJumps(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        if(n==0) return -1;
        if(arr[0]==0) return -1;
        
        int maxReach=0+arr[0];
        int steps=arr[0];
        int jumpCnt=1;
        for(int i=1;i<n;i++){
            if(i==n-1){
                return jumpCnt;
            }
            maxReach=max(maxReach,i+arr[i]);
            steps--;
            if(steps==0){
                jumpCnt++;
                if(i>=maxReach) return -1;
                steps=maxReach-i;
            }
        }
        return jumpCnt;
    }