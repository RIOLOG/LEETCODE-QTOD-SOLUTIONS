class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        //METHOD-1:
        unordered_set<ListNode*>st;
        ListNode* temp = head;
        
        while(temp)
        {
            if (st.find(temp) != st.end())    return true;
            st.insert(temp);
            temp = temp -> next;
        }
        
        return false;
        
        
        
        //method-2:
//         ListNode* fast = head;
//         ListNode* slow = head;
        
//         while(fast and fast -> next)
//         {
//             slow = slow -> next;
//             fast = fast->next->next;
//             if (slow == fast)    return true;
//         }
        
//         return false;
    }
};