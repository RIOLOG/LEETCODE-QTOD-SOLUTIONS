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
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) 
    {
        //STEP - 1 : FIND THE MIDDLE:
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next)
        {
            slow = slow -> next;
            fast = fast->next->next;
        }
        
        //REVERSE THE 2ND HALF OF LINKED LIST:
        ListNode* second = reverse(slow->next);
        slow->next = NULL;
        ListNode* first = head;
        
        //MERGE BOTHLINKED LIST:
        while(second)
        {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
        
    }
};