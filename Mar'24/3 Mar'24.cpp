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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        //method-1:
//         int size = 0;
//         ListNode* temp = head;
//         while(temp != NULL)
//         {
//             size += 1;
//             temp = temp -> next;
//         }
        
//         cout<<size<<endl;
//         if (size == n)   return head -> next;
        
//         int req = size - n;
//         int count = 1;
//         cout<<req<<endl;
        
//         temp = head;
//         while(temp != NULL)
//         {
//             if (req  == count)   temp->next  = temp ->  next -> next;
//             else   temp = temp -> next;
//             count += 1;
//         }
        
//         return head;
        
        
        
        
        
        
        //method-2 : FAST AND SLOW POINTER:
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        while(n)
        {
            fast = fast -> next;
            n -= 1;
        }
        
        while(fast -> next)
        {
            fast = fast->next;
            slow = slow -> next;
        }
        
        slow -> next = slow -> next -> next;
        return dummy -> next;
    }
};