/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        
        std::unordered_set<ListNode*> nodeMap;
       while(head) 
       {
            if(!nodeMap.insert(head).second)
            {
                return true;
            }

        head= head->next;    
       }

       return false;
    }
};
