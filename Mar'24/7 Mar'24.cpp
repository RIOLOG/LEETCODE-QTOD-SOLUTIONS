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
    ListNode* middleNode(ListNode* head) 
    {
        //method1:
//         int size = 0;
//         ListNode* temp = head;
//         while(temp != NULL)
//         {
//             size += 1;
//             temp = temp->next;
//         }
        
//         int req = size / 2;
//         while(req)
//         {
//             head = head -> next;
//             req -= 1;
//         }
//         return head;
        
        
        
        //method-2:
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast  and fast->next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
        
    }
};