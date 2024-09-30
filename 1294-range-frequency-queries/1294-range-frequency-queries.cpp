// segment tree

class RangeFreqQuery {
    struct Node{
        unordered_map<int,int>m;
    };
    vector<Node>seg;
    int n;

    
public:
void build(int node,int left,int right,vector<int>&arr){
    if(left==right){
        seg[node].m[arr[left]]=1;
        return;
    }
    int mid=(left+right)/2;
    build(2*node,left,mid,arr);
    build(2*node+1,mid+1,right,arr);

    for(auto it:seg[2*node].m){
        seg[node].m[it.first]+=it.second;
    }
    for(auto it:seg[2*node+1].m){
        seg[node].m[it.first]+=it.second;
    }
}

int rangeFreq(int node,int left,int right,int l,int r,int value){
    if(right<l or left>r) return 0;
    if(left>=l and right<=r) return seg[node].m[value];

    int mid=(left+right)/2;
    int leftRecursion=rangeFreq(2*node,left,mid,l,r,value);
    int rightRecursion=rangeFreq(2*node+1,mid+1,right,l,r,value);
    return leftRecursion+rightRecursion;
}

    RangeFreqQuery(vector<int>& arr) {
        n=arr.size();
        seg.resize(4*n);
        build(1,0,n-1,arr);
    }
    
    int query(int left, int right, int value) {
        return rangeFreq(1,0,n-1,left,right,value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */