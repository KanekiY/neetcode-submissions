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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if (left&&right) return root;
        return left? left: right;

        /*
        while (root)
        {
            if (p->val < root->val &&
                q->val < root->val)
            {
                root = root->left;
            }
            else if (p->val > root->val &&
                     q->val > root->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
            return nullptr;
        */

    }
};
