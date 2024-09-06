 // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        int n=arr.size();
        int sum=0;
        int currMax=INT_MIN;
        for(int it:arr){
            sum+=it;
            currMax=max(currMax,sum);
            if(sum<0) sum=0;
        }
        return currMax;
    }