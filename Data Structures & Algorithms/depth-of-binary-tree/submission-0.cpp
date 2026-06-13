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
struct Depth
{
    Depth(TreeNode* _node, int _depth) 
    {
        m_root = _node;
        m_depth = _depth;
    }
    TreeNode* m_root = nullptr ;
    int m_depth = 0;
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
        std::queue<Depth> queue;
        int depth = 0;
        queue.push(Depth(root,1));
        while(!queue.empty())
        {
            Depth node = queue.front();
            queue.pop();
            if(node.m_root == nullptr){continue;}
            
            depth = std::max(node.m_depth, depth);

            if(node.m_root->left != nullptr)
            {
                queue.push(Depth(node.m_root->left,node.m_depth+1));
            }
            if(node.m_root->right  != nullptr)
            {
                queue.push(Depth(node.m_root->right,node.m_depth+1));
            }

        }
        return depth;

    }
};
