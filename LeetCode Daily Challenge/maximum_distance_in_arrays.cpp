class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();

        int firstMin = arrays[0][0];
        int firstMax = arrays[0].back();
        int secondMin = INT_MAX;
        int secondMax = INT_MIN;
        int minIndex = 0;
        int maxIndex = 0;

        // Find first min, max and their indices
        for (int i = 1; i < n; i++) {
            if (arrays[i][0] < firstMin) {
                secondMin = firstMin;  // Update second min before first min
                firstMin = arrays[i][0];
                minIndex = i;
            } 
            else if (arrays[i][0] < secondMin) {
                secondMin = arrays[i][0];
            }

            if (arrays[i].back() > firstMax) {
                secondMax = firstMax;  // Update second max before first max
                firstMax = arrays[i].back();
                maxIndex = i;
            } 
            else if (arrays[i].back() > secondMax) {
                secondMax = arrays[i].back();
            }
        }

        // Compute the maximum distance
        int maxDistance = 0;
        if (minIndex != maxIndex) {
            maxDistance = firstMax - firstMin;
        } 
        else {
            maxDistance = max(firstMax - secondMin, secondMax - firstMin);
        }

        return maxDistance;
    }
};
