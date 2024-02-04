class Solution
{
    int dp[501];

private:
    int solve(vector<int> &arr, int n, int k)
    {
        if (n == 1)
            return arr[0];
        return helpme(arr, n - 1, k);
    }

    int helpme(vector<int> &arr, int n, int k)
    {
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int maxi = 0, sum = 0;
        for (int i = 0; i < k; i++)
        {
            if (n - i < 0)
                break;
            maxi = max(maxi, arr[n - i]);
            sum = max(sum, helpme(arr, n - i - 1, k) + maxi * (i + 1));
        }
        return dp[n] = sum;
    }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        // BRUTE-FORCE:
        memset(dp, -1, sizeof(dp));
        int n = arr.size();
        return solve(arr, n, k);
    }
};