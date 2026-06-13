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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        ListNode* left = head;
        ListNode* right = head->next;
        while(right)
        {
            if(right - left < n+1)
            {
                right= right->next;
            }else
            {
                if(right->next != nullptr)
                {
                    left = left->next;
                    right= right->next;
                }
                else
                {
                    //find node
                    break;
                }
            } 
        }
        if(right)
        {
            ListNode* nextNodeAfterRemovedNode = left->next->next;
            left->next = nextNodeAfterRemovedNode;
            //delete left;
             return head;   

        }
        else 
        {
             delete head;
             return nullptr;
        }



        return head;  */
    ListNode dummy(0);
    dummy.next = head;

    ListNode* fast = &dummy;
    ListNode* slow = &dummy;

    // fast 先走 n+1 步
    for (int i = 0; i <= n; i++)
    {
        fast = fast->next;
    }

    // 一起走
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // 删除节点
    ListNode* nodeToDelete = slow->next;

    slow->next = slow->next->next;

    delete nodeToDelete;

    return dummy.next;
    }
};
