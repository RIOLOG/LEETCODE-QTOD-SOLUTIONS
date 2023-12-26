class Solution
{
    int MOD = 1e9 + 7;

private:
    int helpme(int n, int k, int target, vector<vector<int>> &dp)
    {
        if (n == 0)
        {
            if (target == 0)
                return 1;
            else
                return 0;
        }
        if (dp[n][target] != -1)
            return dp[n][target];
        long long count = 0;

        for (int i = 1; i <= k; i++)
        {
            if (i > target)
                break;
            count += (helpme(n - 1, k, target - i, dp)) % MOD;
        }

        return dp[n][target] = count % MOD;
    }

public:
    int numRollsToTarget(int n, int k, int target)
    {
        // memoization:
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return helpme(n, k, target, dp) % MOD;

        // TABUATION:
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                long long count = 0;
                for (int ind = 1; ind <= k; ind++)
                {
                    if (ind > j)
                        break;
                    count += (dp[i - 1][j - ind]) % MOD;
                }
                dp[i][j] = count % MOD;
            }
        }

        return dp[n][target];
    }
};