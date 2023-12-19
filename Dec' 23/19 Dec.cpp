class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));

        //         int dx[] = {-1, 0, 1, 0};
        //         int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int sum = 0, pair = 0;

                // 8 Direction Traversal:
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        int nr = i + dr;
                        int nc = j + dc;

                        if (nr >= 0 and nr < n and nc >= 0 and nc < m)
                        {
                            sum += nums[nr][nc];
                            pair += 1;
                        }
                    }
                }

                if (pair >= 1)
                    ans[i][j] = sum / pair;
                else
                    ans[i][j] = 0;
            }
        }

        return ans;
    }
};