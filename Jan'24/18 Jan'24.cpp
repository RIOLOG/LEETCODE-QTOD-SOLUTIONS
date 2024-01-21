class Solution {
private:
    int helpme(int n, vector<int>&dp)
    {
        if (n < 0)         return 0;
        if (n == 0)        return 1;
        if (dp[n] != -1)   return dp[n];
        
        int take1 = helpme(n-1, dp);
        int take2 = helpme(n-2, dp);
        
        return dp[n] = take1 + take2;
    }
public:
    int climbStairs(int n) 
    {
        //recursion:
        vector<int>dp(n+1,-1);
        return helpme(n, dp);
    }
};