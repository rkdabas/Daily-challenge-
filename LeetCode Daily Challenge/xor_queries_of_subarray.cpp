class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>prefix(n);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]^arr[i];
        }
        vector<int>ans;
        for(auto it:queries){
            int left=it[0];
            int right=it[1];
            ans.push_back(prefix[right]^(left>0 ? prefix[left-1] : 0));
        }
        return ans;
    }
};