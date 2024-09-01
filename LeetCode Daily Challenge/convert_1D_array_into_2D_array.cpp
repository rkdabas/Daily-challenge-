class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n) return {};
        vector<vector<int>>ans(m);
        int ind=0;
        int cnt=0;
        for(int i=0;i<original.size();i++){
            int ele=original[i];
            ans[ind].push_back(ele);
            cnt++;
            if(cnt==n){ 
                cnt=0;
                ind++;
            }
        }
        return ans;
    }
};