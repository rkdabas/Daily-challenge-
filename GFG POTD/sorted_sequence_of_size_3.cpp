
class Solution {
  public:
//   optimised
    vector<int> find3Numbers(vector<int> &arr) {
        int n=arr.size();
        if(n<3) return {};
        
        vector<int>mini(n,INT_MAX);
        mini[0]=arr[0];
        for(int i=1;i<n;i++){
            mini[i]=min(mini[i-1],arr[i]);
        }
        
        vector<int>maxi(n,INT_MIN);
        maxi[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            maxi[i]=max(maxi[i+1],arr[i]);
        }
        
        for(int i=1;i<n-1;i++){
            int second=arr[i];
            int first=mini[i-1];
            int third=maxi[i+1];
            if(first<second and second<third) return {first,second,third};
        }
        return {};
    }
};