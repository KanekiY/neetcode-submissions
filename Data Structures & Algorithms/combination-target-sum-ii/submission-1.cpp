class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> path;

        dfs(candidates, target, 0, path, result);

        return result;
    }

private:
    void dfs(
        vector<int>& candidates,
        int remain,
        int start,
        vector<int>& path,
        vector<vector<int>>& result
    ) {
        if (remain == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > remain) {
                break;
            }

            // 同一层去重
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            path.push_back(candidates[i]);

            // i + 1 表示每个数字只能用一次
            dfs(candidates, remain - candidates[i], i + 1, path, result);

            path.pop_back();
        }
    }
};