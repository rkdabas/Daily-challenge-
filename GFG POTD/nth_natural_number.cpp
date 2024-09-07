 long long findNth(long long n) {
        stack<long long>s;
        while(n>0){
            s.push(n%9);
            n=n/9;
        }
        long long ans=0;
        while(!s.empty()){
            ans=ans*10+(s.top());
            s.pop();
        }
        return ans;
    }