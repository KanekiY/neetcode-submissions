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
    bool Validate(
        TreeNode* node,
        long long minVal,
        long long maxVal)
    {
        if (!node)
            return true;

        if (node->val <= minVal ||
            node->val >= maxVal)
            return false;

        return
            Validate(node->left,
                    minVal,
                    node->val)
            &&
            Validate(node->right,
                    node->val,
                    maxVal);
    }
    
bool isValidBST(TreeNode* root)
{
    return Validate(
        root,
        LLONG_MIN,
        LLONG_MAX);


       /* 问题我只考虑了parent和直接子node的大小关系，根本没有考虑root和 subTree的关系
        if (root == nullptr) return true;
        
        if((!root->left || !root->right) && root->right!=root->left )
        {
            if(root->left)
            {
                if (root->val <= root->left->val)
                {
                    return false;
                } 
                else
                {
                    return isValidBST(root->left);
                }
            }

            if(root->right)
            {
                if (root->val >= root->right->val)
                {
                    return false;
                } 
                else
                {
                    return isValidBST(root->right);
                }
            }
        }

        if(root->left && root->right)
        {
            if (root->val <= root->left->val ||  root->val >= root->right->val) return false;
        }
        bool leftValid = isValidBST(root->left);
         bool rightValid = isValidBST(root->right);
         return leftValid && rightValid;*/
    }
};
