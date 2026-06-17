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
    bool notBalanced = false;
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return !notBalanced;
    }

    int dfs(TreeNode* root)
    {
        if(!root) return 0;
        if(notBalanced) return 0;
        int leftHight = dfs(root->left);
        int rightHight = dfs(root->right);

        if(abs(leftHight- rightHight) > 1)
        {
            notBalanced = true;
            return 0;
        }
        return std::max(leftHight, rightHight) + 1;
    }
};
