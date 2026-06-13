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
  unordered_map<int,int> pos;

    TreeNode* Build(
        vector<int>& preorder,
        int preStart,
        int inLeft,
        int inRight)
    {
        if (inLeft > inRight)
            return nullptr;

        int rootVal =
            preorder[preStart];

        TreeNode* root =
            new TreeNode(rootVal);

        int mid = pos[rootVal];

        int leftSize =
            mid - inLeft;

        root->left =
            Build(
                preorder,
                preStart + 1,
                inLeft,
                mid - 1);

        root->right =
            Build(
                preorder,
                preStart + leftSize + 1,
                mid + 1,
                inRight);

        return root;
    }

    TreeNode* buildTree(
        vector<int>& preorder,
        vector<int>& inorder)
    {
        for(int i=0;i<inorder.size();i++)
        {
            pos[inorder[i]] = i;
        }

        return Build(
            preorder,
            0,
            0,
            inorder.size()-1);
    }
};
