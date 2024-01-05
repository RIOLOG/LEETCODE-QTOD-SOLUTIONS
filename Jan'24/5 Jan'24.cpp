class Solution
{
public:
    int rec(int ind, int prev, int n, vector<int> &nums)
    {
        if (ind == n)
            return 0;

        int len1 = 0, len2 = 0;

        len1 = 0 + rec(ind + 1, prev, n, nums);

        if (prev == -1 || nums[ind] > nums[prev])
        {
            len2 = 1 + rec(ind + 1, ind, n, nums);
        }

        return max(len1, len2);
    }

    int helpme(int ind, int prev, int n, vector<vector<int>> &dp, vector<int> &nums)
    {
        if (ind == n)
            return 0;
        if (dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1];

        int len1 = 0, len2 = 0;
        len1 = 0 + helpme(ind + 1, prev, n, dp, nums);

        if (prev == -1 or nums[prev] < nums[ind])
        {
            len2 = 1 + helpme(ind + 1, ind, n, dp, nums);
        }

        return dp[ind][prev + 1] = max(len1, len2);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        // RECURRANCE:
        int n = nums.size();
        int ind = 0;
        int prev = -1;
        return rec(ind, prev, n, nums);

        // MEMOIZATION:
        int n = nums.size();
        int ind = 0;
        int prev = -1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return helpme(ind, prev, n, dp, nums);

        // Tabulation:
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            dp[n][i] = 0;
        }

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev = ind - 1; prev >= -1; prev--)
            {
                int len1 = 0, len2 = 0;
                len1 = 0 + dp[ind + 1][prev + 1];

                if (prev == -1 or nums[prev] < nums[ind])
                {
                    len2 = 1 + dp[ind + 1][ind + 1];
                }

                dp[ind][prev + 1] = max(len1, len2);
            }
        }

        return dp[0][0];

        // Loops:
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());

        // METHOD-2 :
        vector<int> v;
        v.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > v[v.size() - 1])
            {
                v.push_back(nums[i]);
            }
            else
            {
                int find = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                v[find] = nums[i];
            }
        }
        return v.size();
    }
};