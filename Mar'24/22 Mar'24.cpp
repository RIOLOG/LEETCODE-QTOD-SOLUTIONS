class Solution
{
private:
    ListNode *helpmeReverse(ListNode *head)
    {
        ListNode *prev = NULL;

        while (head)
        {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        // using VEECTORR:
        //         vector<int>ans;
        //         while(head)
        //         {
        //             ans.push_back(head -> val);
        //             head = head -> next;
        //         }

        //         int n = ans.size();
        //         for (int i=0; i<n/2; i++)
        //         {
        //             if (ans[i] != ans[n - i - 1])   return false;
        //         }
        //         return true;

        // reversing the mid Linklist:
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;

        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = helpmeReverse(slow->next);
        slow = slow->next;

        while (slow != NULL)
        {
            if (slow->val != head->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};