#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

long long find(int ind, vector<double>& v1, vector<double>& v2) {
    double curr = v1[ind];
    int s = 0;
    int e = v2.size() - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (v2[mid] > curr) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return v2.size() - s;  // This gives the number of elements greater than `curr`
}

long long countPairs(vector<int> &arr, vector<int> &brr) {
    // Your Code goes here.
    
    vector<double> v1;
    for (auto it : arr) {
        v1.push_back(log(it));  // Adjusted the expression
    }
    
    vector<double> v2;
    for (auto it : brr) {
        v2.push_back(log(it));  // Adjusted the expression
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    long long ans = 0;
    for (int i = 0; i < v1.size(); i++) {
        long long cnt = find(i, v1, v2);
        ans += cnt;
    }
    return ans;
}
