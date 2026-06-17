class Solution {
public:
  bool validTree(int n, vector<vector<int>>& edges) {
        //union find 找环，dfs找 连通。然后利用树的性质 边数 = 节点数-1
        if (edges.size() != n - 1) {
            return false;
        }

        vector<int> parent(n);
        vector<int> rank(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];

            if (find(parent, a) == find(parent, b)) {
                return false; // already connected, adding this edge creates cycle
            }

            unite(parent, rank, a, b);
        }

        return true;
    }

private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]); // path compression
        }

        return parent[x];
    }

    void unite(vector<int>& parent, vector<int>& rank, int a, int b) {
        int rootA = find(parent, a);
        int rootB = find(parent, b);

        if (rootA == rootB) return;

        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootA] = rootB;
            rank[rootB]++;
        }
    }
};
