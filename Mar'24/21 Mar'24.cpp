class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *NH = NULL;
        while (head != NULL)
        {
            ListNode *next = head->next;
            head->next = NH;
            NH = head;
            head = next;
        }

        return NH;
    }
};