class Solution {
public:
// approach IV -> optimised
int solve(vector<int>&nums,int diff){
    int n=nums.size();
    int cnt=0;
    int i=0;
    int j=1;
    while(j<n){
        while(nums[j]-nums[i] > diff){
            i++;
        }
        cnt+=(j-i);
        j++;
    }
    return cnt;
}
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int s=0;
        int e=nums[n-1]-nums[0];
        int ans=0;

        while(s<=e){
            int mid=s+(e-s)/2;
            int countPairs=solve(nums,mid);
            if(countPairs<k){
                s=mid+1;
            }
            else{
                ans=mid;
                e=mid-1;
            }
        }
        return ans;
    }
};