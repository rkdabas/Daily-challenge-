// return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        long long int prod=1;
        int cnt=0;
        for(auto it:nums){
            if(it!=0) prod=prod*it;
            if(it==0) cnt++;
        }
        vector<long long int>ans(nums.size(),0);
        if(cnt==1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0) ans[i]=0;
                else ans[i]=prod;
            }
        }
        else if(cnt==0){
            for(int i=0;i<nums.size();i++){
                long long int temp=prod;
                ans[i]=(temp/nums[i]);
            }
        }
        
        return ans;
    }