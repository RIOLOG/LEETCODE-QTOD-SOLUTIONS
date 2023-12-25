class Solution
{
private:
    int helpme(int ind, string s, vector<int> &dp)
    {
        if (ind == s.size())
            return 1;
        if (dp[ind] != -1)
            return dp[ind];

        int helpme1 = 0, helpme2 = 0;
        if (s[ind] != '0')
            helpme1 = helpme(ind + 1, s, dp);

        if (ind + 1 < s.length() && (s[ind] == '1' || (s[ind] == '2' && s[ind + 1] <= '6')))
            helpme2 = helpme(ind + 2, s, dp);

        return dp[ind] = helpme2 + helpme1;
    }

public:
    int numDecodings(string s)
    {
        // memoization:
        if (s[0] == '0')
            return 0;
        int n = s.size();
        vector<int> dp(n, -1);
        return helpme(0, s, dp);

        // tabulation:
        if (s[0] == '0')
            return 0;
        int n = s.size();
        vector<int> dp(n + 1, -1);
        dp[n] = 1;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            int helpme1 = 0, helpme2 = 0;
            if (s[ind] != '0')
                helpme1 = dp[ind + 1];

            if (ind + 1 < s.length() && (s[ind] == '1' || (s[ind] == '2' && s[ind + 1] <= '6')))
                helpme2 = dp[ind + 2];

            dp[ind] = helpme2 + helpme1;
        }

        return dp[0];
    }
};