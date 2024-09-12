class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt=0;
        int mask=0;
        for(int i=0;i<allowed.size();i++){
            int ch=allowed[i]-'a';
            mask=mask | (1<<ch);
        }

        for(auto it:words){
            string s=it;
            bool isPresent=true;
            for(int i=0;i<s.size();i++){
                int k=s[i]-'a';
                if(((mask>>k)&1) == 0){
                    isPresent=false;
                    break;
                }
            }
            if(isPresent == true) cnt++;
        }
        return cnt;
    }
};