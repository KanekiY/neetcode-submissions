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
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> st;
        TreeNode* current = root;
        int i = 0;
        while (current || !st.empty())
        {
            while (current)
            {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();
            i++;
            if(i == k) {return current->val;}

            current = current->right;
        }

        return 0;
    }
};
