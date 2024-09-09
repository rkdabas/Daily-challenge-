   void sort012(vector<int>& arr) {
        int n=arr.size();
        int zero=0;
        int one=0;
        int two=n-1;
        while(one<=two){
            if(arr[one]==1){
                one++;
            }
            else if(arr[one]==0){
                swap(arr[one],arr[zero]);
                zero++;
                one++;
            }
            else{
                swap(arr[one],arr[two]);
                two--;
            }
        }
    }