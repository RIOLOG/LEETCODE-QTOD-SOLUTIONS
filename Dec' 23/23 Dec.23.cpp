class Solution
{
public:
    bool isPathCrossing(string path)
    {
        vector<pair<int, int>> mp;
        int x = 0;
        int y = 0;
        mp.emplace_back(x, y);

        for (int i = 0; i < path.size(); i++)
        {
            if (path[i] == 'N')
                y += 1;
            else if (path[i] == 'S')
                y -= 1;
            else if (path[i] == 'E')
                x += 1;
            else
                x -= 1;

            for (auto &p : mp)
            {
                if (p.first == x && p.second == y)
                    return true;
            }
            mp.emplace_back(x, y);
        }

        return false;
    }
};