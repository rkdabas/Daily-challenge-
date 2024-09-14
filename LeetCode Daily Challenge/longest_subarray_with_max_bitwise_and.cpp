class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());

        int ans=0;
        int i=0;
        int j=0;
        while(j<n){
            while(j<n and nums[j]==maxi){
                ans=max(ans,j-i+1);
                j++;
            }
            j++;
            i=j;
        }
        return ans;
    }
};