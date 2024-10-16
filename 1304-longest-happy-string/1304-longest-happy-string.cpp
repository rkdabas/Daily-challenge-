class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s="";
        if(a>=b and a>=c){
            if(a>=2){
                s+="aa";
                a-=2;
            }
            else{
                s+='a';
                a-=1;
            }
        }
        else if(b>=a and b>=c){
            if(b>=2){
                s+="bb";
                b-=2;
            }
            else{
                s+='b';
                b-=1;
            }
        }
        else if(c>=a and c>=a){
            if(c>=2){
                s+="cc";
                c-=2;
            }
            else{
                s+='c';
                c-=1;
            }
        }
        while(true){
            while(a>=b and a>=c){
                if(s.back()=='a'){
                    if(b!=0){
                        s+='b';
                        b--;
                    }
                    else if(c!=0){
                        s+='c';
                        c--;
                    }
                    else return s;
                }
                else{
                    if(a>=2){
                        s+="aa";
                        a-=2;
                    }
                    else{
                        s+='a';
                        a--;
                    }
                }
            }
            while(b>=a and b>=c){
                if(s.back()=='b'){
                    if(a!=0){
                        s+='a';
                        a--;
                    }
                    else if(c!=0){
                        s+='c';
                        c--;
                    }
                    else return s;
                }
                else{
                    if(b>=2){
                        s+="bb";
                        b-=2;
                    }
                    else{
                        s+='b';
                        b--;
                    }
                }
            }
            while(c>=a and c>=b){
                if(s.back()=='c'){
                    if(a!=0){
                        s+='a';
                        a--;
                    }
                    else if(b!=0){
                        s+='b';
                        b--;
                    }
                    else return s;
                }
                else{
                    if(c>=2){
                        s+="cc";
                        c-=2;
                    }
                    else{
                        s+='c';
                        c--;
                    }
                }       
            }
            if(a==0 and b==0 and c==0) break;
        }
        return s;
    }
};