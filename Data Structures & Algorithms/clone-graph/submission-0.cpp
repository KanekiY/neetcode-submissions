/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
 Node* DFS(Node* i_node, unordered_map<Node*, Node*>& oldToNew)
 {
    if(i_node == nullptr) return nullptr;
    if(oldToNew.find(i_node) != oldToNew.end())  return oldToNew[i_node];
    
    oldToNew[i_node] = new Node(i_node->val);
  
    for(auto neighbor: i_node->neighbors)
    {
         oldToNew[i_node]->neighbors.push_back(DFS(neighbor, oldToNew));
    }
    return oldToNew[i_node];
 }

Node* cloneGraph(Node* node) {
       if(node == nullptr)
            return nullptr;
        // old node -> cloned node
        unordered_map<Node*, Node*> oldToNew;
        return DFS(node, oldToNew);
       
       
       /*
        if (node == nullptr)
            return nullptr;

        // old node -> cloned node
        unordered_map<Node*, Node*> oldToNew;

        queue<Node*> q;

        // clone start node
        Node* cloneStart = new Node(node->val);

        oldToNew[node] = cloneStart;
        q.push(node);

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();

            // 当前clone节点
            Node* curClone = oldToNew[cur];

            for (Node* nei : cur->neighbors) {

                // 如果neighbor还没clone
                if (!oldToNew.count(nei)) {

                    oldToNew[nei] = new Node(nei->val);

                    q.push(nei);
                }

                // 连接 clone graph
                curClone->neighbors.push_back(oldToNew[nei]);
            }
        }

        return cloneStart;*/
    }
};
