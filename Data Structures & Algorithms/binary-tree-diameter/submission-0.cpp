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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxCount = 0;
         dfs(root,0,maxCount);
         return maxCount;
    }

    int dfs(TreeNode* root, int count, int& maxCount) // 注意！！！ 传入进去count是错的，算的就是root到leaf的高度，而不是当前sub tree的高度了
    {
        if(!root) return 0;
        int left = dfs(root->left, count/*+1 不要加1*/, maxCount);
        int right = dfs(root->right, count, maxCount);
          maxCount =std::max(maxCount, left + right);
        return std::max(left, right)+1;
    }
};
