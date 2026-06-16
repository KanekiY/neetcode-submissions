class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);//很重要，一定要初始化，不然有的indegree搜找不到
        for(vector<int>& prerequisity: prerequisites)
        {
            graph[prerequisity[0]].push_back(prerequisity[1]);
            indegree[prerequisity[1]]++;
        }
        std::queue<int> bfsQueue;
        
        for(int i = 0; i< indegree.size(); i++ )
        {
            if(indegree[i] == 0) bfsQueue.push(i);
        }

        int complete = 0;
        while(!bfsQueue.empty())
        {
            int course = bfsQueue.front();
            bfsQueue.pop();
            complete++;

            for(int dependentCourse: graph[course] )
            {
                indegree[dependentCourse]--;

                if(indegree[dependentCourse] == 0)
                {
                    bfsQueue.push(dependentCourse);
                }
            }
        }

        return complete == numCourses;

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
};
