class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        queue<int> q;

        for (int i = 0; i < tickets.size(); i++)
            q.push(i);
        int time = 0;

        while (!q.empty())
        {
            time += 1;

            int top = q.front();
            q.pop();

            tickets[top] -= 1;
            if (top == k and tickets[top] == 0)
                return time;

            if (tickets[top] > 0)
                q.push(top);
        }

        return time;
    }
};