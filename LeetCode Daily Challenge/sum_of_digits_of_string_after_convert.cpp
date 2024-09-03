class Solution {
public:
    int getLucky(string s, int k) {
        int n=s.size();
        string temp="";
        for(auto ch:s){
            int digit=ch-'a'+1;
            temp+=(to_string(digit));
        }

        while(k--){
            int sum=0;
            for(char ch:temp){
                sum+=(ch-'0');
            }
            temp=to_string(sum);
        }
        return stoi(temp);
    }
};