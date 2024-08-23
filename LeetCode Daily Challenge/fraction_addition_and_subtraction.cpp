class Solution {
public:
    string fractionAddition(string expression) {
        int n=expression.size();
        
        int nume=0;
        int deno=1;

        int i=0;
        while(i<n){
            int currNume=0;
            int currDeno=0;

            bool negative=(expression[i]=='-');
            if(expression[i]=='-' or expression[i]=='+') i++;

            while(i<n and isdigit(expression[i])){
                currNume=currNume*10+(expression[i]-'0');
                i++;
            }
            if(negative==true){
                currNume*=-1;
            }
            i++;

            while(i<n and isdigit(expression[i])){
                currDeno=currDeno*10+(expression[i]-'0');
                i++;
            }
            nume=nume*currDeno+currNume*deno;
            deno=deno*currDeno;
        }

        int GCD=abs(__gcd(nume,deno));
        nume=nume/GCD;
        deno=deno/GCD;

        return to_string(nume) + "/" + to_string(deno);

    }
};