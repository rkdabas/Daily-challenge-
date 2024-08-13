#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// space optimised -> without using set
void solve(int i,vector<int>&arr,int n,int target,vector<int>&v,vector<vector<int>>&ans){
    if(target==0){
        ans.push_back(v);
        return;
    }
    if(i==n){
        return;
    }
    if(arr[i]<=target){
        v.push_back(arr[i]);
        solve(i+1,arr,n,target-arr[i],v,ans);
        v.pop_back();
    }
    int j=i+1;
    while(j<n and arr[j]==arr[j-1]){
        j++;
    }
    solve(j,arr,n,target,v,ans);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        solve(0,candidates,n,target,v,ans);
        return ans;
    }
};

int main(){
  vector<int>arr;
  cin >> arr;
  int target;
  cin >> target;
  combinationSum2(arr, target);
  return 0;
}