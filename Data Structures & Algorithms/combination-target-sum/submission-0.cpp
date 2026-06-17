class Solution {
public:
    struct Context
    {
        vector<int> path;
        int startIndex;
        int targetNumber;
        Context (int i_startIndex, int i_targetNum, vector<int> i_path)
        {
            startIndex = i_startIndex;
            targetNumber = i_targetNum;
            path = i_path;
        }
    };
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
           sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        stack<Context> stk;
        stk.push(Context(0,target, {}));

        while(!stk.empty())
        {
            Context current = stk.top();
            stk.pop();
            if(  current.targetNumber == 0)
            {
                results.push_back(current.path);
                continue;
            }
    
            for (int i = current.startIndex; i < nums.size(); i++) {
                if (nums[i] > current.targetNumber)// remain 一定要基于
                {
                    break;
                }

                vector<int> path = current.path;
                path.push_back(nums[i]);
                stk.push(Context(i,current.targetNumber - nums[i], path));
            }
        } 

       
     return results;

    }

};
