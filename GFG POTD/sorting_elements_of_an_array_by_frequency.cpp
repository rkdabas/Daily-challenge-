    
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first>b.first) return a;
        else if(b.first>a.first) return b;
        else if(a.first==b.first){
            if(a.second<b.second) return a;
            else return b;
        }
    }
    vector<int> sortByFreq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>m;
        for(auto it:arr) m[it]++;
        
        vector<pair<int,int>>v;
        for(auto it:m){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),cmp);
        
        vector<int>ans;
        for(int i=0;i<v.size();i++){
            int cnt=v[i].second;
            int ele=v[i].first;
            while(cnt--){
                ans.push_back(ele);
            }
        }
        return ans;
        
    }