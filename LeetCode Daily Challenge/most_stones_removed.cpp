class dsu {
public:
    vector<int> parent;
    vector<int> rank;
    
    dsu(int n) {
        parent.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
        rank.resize(n, 0);
    }

    int findParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int node1, int node2) {
        int pu = findParent(node1);
        int pv = findParent(node2);

        if (pu != pv) {
            if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else {
                parent[pu] = pv;
                rank[pv]++;
            }
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int m = stones.size();
        if (m == 1) return 0;

        int maxRow = 0, maxCol = 0;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        int n = max(maxRow, maxCol) + 1;
        dsu ds(2 * n);

        unordered_map<int, int> visited;
        for (int i = 0; i < m; i++) {
            int row = stones[i][0];
            int col = stones[i][1] + n; 
            ds.unionByRank(row, col);
            visited[row] = 1;
            visited[col] = 1;
        }

        int cnt = 0;
        for (auto it : visited) {
            if (ds.findParent(it.first) == it.first) {
                cnt++;
            }
        }
        return m - cnt;
    }
};
