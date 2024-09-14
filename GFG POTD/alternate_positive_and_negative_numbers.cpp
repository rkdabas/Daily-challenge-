  void rearrange(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>v;
        vector<int>d;
        for(auto it:arr){
            if(it<0) v.push_back(it);
            else d.push_back(it);
        }
        int i=0;
        int j=0;
        int k=0;
        while(j<v.size() and i<d.size()){
            if(k%2 == 0){
                arr[k]=d[i];
                i++;
                k++;
            }
            else{
                arr[k]=v[j];
                j++;
                k++;
            }
        }
        while(j<v.size()){
            arr[k]=v[j];
            k++;
            j++;
        }
        while(i<d.size()){
            arr[k]=d[i];
            k++;
            i++;
        }
    }