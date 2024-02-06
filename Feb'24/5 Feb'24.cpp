class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> vis(256, -1);
        for (int i = 0; i < s.size(); i++)
        {
            if (vis[s[i]] == -1)
                vis[s[i]] = i;
            else
                vis[s[i]] = -2;
        }

        int minIndex = INT_MAX;
        for (int i = 0; i < 256; i++)
        {
            if (vis[i] >= 0)
                minIndex = min(minIndex, vis[i]);
        }

        if (minIndex == INT_MAX)
            return -1;
        return minIndex;
    }
};