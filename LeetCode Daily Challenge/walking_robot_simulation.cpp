class Solution {
public:

map<pair<int,int>,int>m;
int solve(vector<int>&arr,vector<vector<int>>&commands,int n1,int n2){
    int direction=0;
    int currRow=0;
    int currCol=0;
    int ans=0;
    for(int i=0;i<n1;i++){
        if(arr[i]==-1){
            direction=(direction+1)%4;
        }
        else if(arr[i]==-2){
            if(direction==0) direction=3;
            else direction--;
        }
        else if(arr[i]>0){
            int k=arr[i];
            int nCol=currCol;
            int nRow=currRow;
            if(direction==0){    // north  
                while(k--){
                    nRow++;
                    if(m.find({nRow,nCol})!=m.end()){
                        break;
                    }
                    currRow=nRow;
                }
            }
            else if(direction == 1){   // east
                while(k--){
                    nCol++;
                    if(m.find({nRow,nCol})!=m.end()){
                        break;
                    }
                    currCol=nCol;
                }
            }
            else if(direction == 2){   // south
                while(k--){
                    nRow--;
                    if(m.find({nRow,nCol})!=m.end()){
                        break;
                    }
                    currRow=nRow;
                }
            }
            else if(direction == 3){   // west
                while(k--){
                    nCol--;
                    if(m.find({nRow,nCol})!=m.end()){
                        break;
                    }
                    currCol=nCol;
                }
            }
            ans=max(ans,(currRow*currRow)+(currCol*currCol));
        }
    }
    return ans;
}
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n1=commands.size();
        int n2=obstacles.size();
        for(auto it:obstacles){
            int row=it[0];
            int col=it[1];
            m[{col,row}]++;
        }
        return solve(commands,obstacles,n1,n2);
    }
};