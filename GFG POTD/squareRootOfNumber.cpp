// using binary search 
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        long long int s=1;
        long long int e=n/2+1;
        long long int ans=-1;
        while(s<=e){
            long long int mid=(s+e)/2;
            if((mid*mid)==n){
                return mid;
            }
            if((mid*mid)>n){
                e=mid-1;
            }
            else{
                ans=mid;
                s=mid+1;
            }
        }
        return ans;
    }
};