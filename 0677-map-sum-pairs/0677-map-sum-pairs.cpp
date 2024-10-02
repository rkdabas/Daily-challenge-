class MapSum {
public:
// brute
unordered_map<string,int>m;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key]=val;
    }
    
    int sum(string prefix) {
        int n=prefix.size();
        int ans=0;
        for(auto it:m){
            string s=it.first;
            if(s.substr(0,n)==prefix) ans+=it.second;
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */