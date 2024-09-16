class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // convert hour format into minute format and store in time vector and sort it
        vector<int>time;
        for(int i=0;i<timePoints.size();i++){
            string s=timePoints[i];
            int hour=stoi(s.substr(0,2));
            int min=stoi(s.substr(3,2));
            int total=hour*60+min;
            time.push_back(total);
        }
        sort(time.begin(),time.end());

        // find the minimum difference between adjacent times
        int mini=INT_MAX;
        int n=time.size();
        for(int i=0;i<n-1;i++){
            int diff=time[i+1]-time[i];
            mini=min(mini,diff);
        }
        // 24 hours * 60 min = 1440 min
        // find the minimum diff between last hour and 24:00 
        int last=(time[0]+1440) - time[n-1];
        mini=min(mini,last);
        return mini;


    }
};