int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int n1=arr1.size();
        int n2=arr2.size();
        
        vector<int>pre1(n1,0);
        pre1[0]=arr1[0];
        for(int i=1;i<n1;i++){
            pre1[i]=pre1[i-1]+arr1[i];
        }
        
        vector<int>pre2(n2,0);
        pre2[0]=arr2[0];
        for(int i=1;i<n2;i++){
            pre2[i]=pre2[i-1]+arr2[i];
        }
        
        int i=0;
        int j=0;
        int ans=0;
        int last1=-1;
        int last2=-1;
        while(i<n1 and j<n2){
            if(arr1[i]==arr2[j]){
                int s1=0;
                if(i>0) s1=pre1[i-1];
                if(last1!=-1) s1-=pre1[last1];
                last1=i;
                
                int s2=0;
                if(j>0) s2=pre2[j-1];
                if(last2!=-1) s2-=pre2[last2];
                last2=j;
                
                if(s1>=s2){
                    ans+=s1+arr1[i];
                    i++;
                }
                else{
                    ans+=s2+arr2[j];
                    j++;
                }
            }
            else if(arr1[i]<arr2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        int s1=pre1[n1-1]-(last1==-1 ? 0 : pre1[last1]);
        int s2=pre2[n2-1]-(last2==-1 ? 0 :  pre2[last2]);
        if(s1>=s2) ans+=s1;
        else ans+=s2;
        
        return ans;
    }