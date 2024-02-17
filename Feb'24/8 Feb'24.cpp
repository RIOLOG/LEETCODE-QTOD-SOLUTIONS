class Solution {
// private:
//     int helpme(int n, vector<int>& dp)
//     {
//         if (n < 4)    return n;
//         if (dp[n] != -1)    return dp[n];
        
//         int ans = INT_MAX;
//         for (int i = 1; i*i <= n ;i++)
//         {
//             ans = min(ans, 1 + helpme(n - i*i, dp));
//         }
        
//         return dp[n] = ans;
//     }
    
public:
int numSquares(int n) 
{
        vector<int>dp(n+1,0);
        
        for(int i=1;i<=n;i++)
        {
            int ans = INT_MAX;
            for(int j=1;j<=sqrt(i);j++)
            {
                if(j*j <= i)
                {
                     ans = min(ans , 1 + dp[n-j*j]);
                }
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};