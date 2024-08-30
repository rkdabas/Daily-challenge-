
class Solution {
public:
    vector<vector<int>> ans;

    void solve(int row, int n, vector<int>& up, vector<int>& left, vector<int>& right, vector<int>& v) {
        if (row == n) {
            ans.push_back(v);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (up[col] == 0 && left[row + col] == 0 && right[n - 1 + row - col] == 0) {
                up[col] = 1;
                left[row + col] = 1;
                right[n - 1 + row - col] = 1;
                v.push_back(col + 1);  
                solve(row + 1, n, up, left, right, v);
                up[col] = 0;
                left[row + col] = 0;
                right[n - 1 + row - col] = 0;
                v.pop_back();
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<int> up(n, 0), leftDiagonal(2 * n - 1, 0), rightDiagonal(2 * n - 1, 0), v;
        solve(0, n, up, leftDiagonal, rightDiagonal, v);
        return ans;
    }
};