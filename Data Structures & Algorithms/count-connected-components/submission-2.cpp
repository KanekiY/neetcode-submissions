class Solution {
public:

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents(n);// 可以是个map, <Node*, Node*>
        std::unordered_set<int> results;
        for(int i = 0; i<n;i++ )
        {
            parents[i] = i;
        }
    int count = n; // 一开始每个点都是一个独立连通块
        for(auto& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            if(unite(results, parents,a,b))
            {
                count--;
            };
        }
        return count;

    }

    int find(vector<int>& parents, int node)
    {
        if(parents[node] != node)
        {
            parents[node] = find(parents, parents[node]);
        }
        return parents[node];
    }

    bool unite(std::unordered_set<int>& results, vector<int>& parents, int nodeA, int nodeB)
    {

        int rootA = find(parents, nodeA);
        int rootB = find(parents, nodeB);

        if(rootA == rootB){ return false;}
      
        parents[rootA] = rootB;
        return true;
    }
};
