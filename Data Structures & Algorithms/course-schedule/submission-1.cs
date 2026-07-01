public class Solution {
    bool dfs(
        int course,
        List<List<int>> graph,
        List<int> state)
    {
        if(state[course] == 1)
        {
            return false;
        }

        if(state[course] == 2)
        {
            return true;
        }

        state[course] = 1; // 这点是back tracking的思想，我们先标记

        foreach(int next in graph[course])
        {
            if(!dfs(next, graph, state))
            {
                return false;
            }
        }

        state[course] = 2; //发现没环以后标记为2， 剪掉一个枝叶

        return true;
    }
    public bool CanFinish(int numCourses, int[][] prerequisites) {
        List<List<int>> graph = new  List<List<int>>(numCourses);
        for (int i = 0; i < numCourses; i++)
        {
            graph.Add(new List<int>());
        }
        foreach (var p in prerequisites) // 构建graph时候，我们构建的是 course - pre 图，因为我们要深度搜索 更上层有没有depend到我们自己的
        {
            graph[p[1]].Add(p[0]);
        }

        List<int> state =  Enumerable.Repeat(0, numCourses).ToList();
        for(int i = 0; i < numCourses; i++)
        {
            if(!dfs(i, graph, state))
            {
                return false;
            }
        }

        return true;
    }
/* // dfs 解法
        bool dfs(
        int course,
        vector<vector<int>>& graph,
        vector<int>& state)
    {
        if(state[course] == 1)
        {
            return false;
        }

        if(state[course] == 2)
        {
            return true;
        }

        state[course] = 1; // 这点是back tracking的思想，我们先标记

        for(int next : graph[course])
        {
            if(!dfs(next, graph, state))
            {
                return false;
            }
        }

        state[course] = 2; //发现没环以后标记为2， 剪掉一个枝叶

        return true;
    }

    bool canFinish(
        int numCourses,
        vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(numCourses);

        for(auto& p : prerequisites) // 构建graph时候，我们构建的是 course - pre 图，因为我们要深度搜索 更上层有没有depend到我们自己的
        {
            graph[p[1]].push_back(p[0]);
        }

        vector<int> state(numCourses, 0);

        for(int i = 0; i < numCourses; i++)
        {
            if(!dfs(i, graph, state))
            {
                return false;
            }
        }

        return true;
    }
    */
}
