/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxSum = INT_MIN;

    int DFS(TreeNode* node)
    {
        if (node == nullptr)
            return 0;

        int leftGain = std::max(0, DFS(node->left));
        int rightGain = std::max(0, DFS(node->right));

        int pathThroughNode = node->val + leftGain + rightGain; //计算max sum时候，比较的是当前的path值

        maxSum = std::max(maxSum, pathThroughNode);

        return node->val + std::max(leftGain, rightGain); // 返回给父节点时，只能带一条边上去。
    }

    int maxPathSum(TreeNode* root)
    {
        DFS(root);
        return maxSum;
    }
};
