// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        long long n,q;
        cin>>n>>q;

        vector<long long>height(n);
        for(int i=0;i<n;i++) cin>>height[i];
        
        vector<long long>question(q);
        for(int i=0;i<q;i++) cin>>question[i];

        vector<long long>prefix(n);
        prefix[0]=height[0];

        vector<long long>maxi(n);
        maxi[0]=height[0];

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+height[i];
            maxi[i]=max(maxi[i-1],height[i]);
        }

        
        for(int i=0;i<q;i++){
            long long ans=0;
            long long ind=upper_bound(maxi.begin(),maxi.end(),question[i])-maxi.begin()-1;
            if(ind>=0) ans=prefix[ind];
            cout<<ans<<" ";
            
        }
        cout<<endl;

    }
    return 0;
}