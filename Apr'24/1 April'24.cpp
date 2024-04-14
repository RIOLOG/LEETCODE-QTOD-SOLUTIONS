class Solution {
private:
    bool helpme(int ind, string s, int count, vector<vector<int>>& dp) {
        int n = s.size();
        if (count < 0)    return false;
        if (ind >= n)     return (count == 0);
        
        if (dp[ind][count + n] != -1)    return dp[ind][count + n];

        if (s[ind] == '(')
            return dp[ind][count + n] = helpme(ind + 1, s, count + 1, dp);
        else if (s[ind] == ')')
            return dp[ind][count + n] = helpme(ind + 1, s, count - 1, dp);
        else
            return dp[ind][count + n] = helpme(ind + 1, s, count + 1, dp) or
                                        helpme(ind + 1, s, count - 1, dp) or
                                        helpme(ind + 1, s, count, dp);
    }

public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * n + 1, -1));
        return helpme(0, s, 0, dp);
    }
}; 