class Solution
{
public:
    int pivotInteger(int n)
    {
        int pivot = -1;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += i;
        }

        int left = 0;
        for (int i = 1; i <= n; i++)
        {
            int right = sum - left;
            left += i;

            if (left == right)
            {
                pivot = i;
                break;
            }
        }

        return pivot;
    }
};