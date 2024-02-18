class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        int m = meetings.size();

        sort(meetings.begin(), meetings.end());

        vector<long long> room(n, 0);

        vector<int> ans(n, 0);
        for (int i = 0; i < m; i++)
        {
            int start = meetings[i][0];
            int end = meetings[i][1];

            int minendtime = LLONG_MAX;
            int roomno = -1;
            bool flag = false;

            for (int j = 0; j < n; j++)
            {
                if (start >= room[j])
                {
                    room[j] = end;
                    ans[j]++;
                    flag = true;
                    break;
                }
                if (minendtime > room[j])
                {
                    minendtime = room[j];
                    roomno = j;
                }
            }
            if (flag == false)
            {
                // room[roomno] = (minendtime - start ) + end;
                ans[roomno]++;
            }
        }

        int freq = -1;
        int ind = -1;

        for (int i = 0; i < n; i++)
        {
            if (freq < ans[i])
            {
                freq = ans[i];
                ind = i;
            }
        }
        return ind;
    }
};