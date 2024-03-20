class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *temp1 = list1;
        ListNode *temp2 = list2;
        ListNode *dummy = list1;
        int count = 1;

        while (temp2->next != NULL)
        {
            if (count == a)
            {
                dummy = dummy->next;
                temp1->next = temp2;

                while (count < b)
                {
                    dummy = dummy->next;
                    count += 1;
                }

                while (temp2->next != NULL)
                    temp2 = temp2->next;
            }

            else
            {
                count += 1;
                temp1 = temp1->next;
                dummy = dummy->next;
            }
        }

        if (dummy->next != NULL)
        {
            temp2->next = dummy->next;
        }

        return list1;
    }
};