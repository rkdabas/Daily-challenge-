class Solution {
public:
// using merge sort
int cnt=0;
void merge(vector<int>&arr,int n,int s,int mid,int e){
    int left=s;
    int right=mid+1;
    for(int i=left;i<=mid;i++){
        while(right<=e and arr[i]>((2LL)*arr[right])){
            right++;
        }
        cnt+=(right-(mid+1));
    }

    left=s;
    right=mid+1;
    vector<int>temp;
    while(left<=mid and right<=e){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=e){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=s;i<=e;i++){
        arr[i]=temp[i-s];
    }
}
void mergeSort(vector<int>&arr,int n,int s,int e){
    int mid=(s+e)/2;
    if(s<e){
        mergeSort(arr,n,s,mid);
        mergeSort(arr,n,mid+1,e);
        merge(arr,n,s,mid,e);
    }
}
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,n,0,n-1);
        return cnt;
    }
};