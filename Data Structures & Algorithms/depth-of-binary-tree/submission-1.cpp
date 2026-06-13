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

        if (root == nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + std::max(left,right);
        /*
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
        */
        /*
            int maxDepth(TreeNode* root) {
                if (!root)
                    return 0;

                std::queue<TreeNode*> q;
                q.push(root);

                int depth = 0;

                while (!q.empty()) {
                    int levelSize = q.size();

                    for (int i = 0; i < levelSize; ++i) {
                        TreeNode* node = q.front();// bfs 是按层数循环的
                        q.pop();

                        if (node->left)
                            q.push(node->left);

                        if (node->right)
                            q.push(node->right);
                    }

                    depth++;
                }

                return depth;
            }
        */
    }
};
