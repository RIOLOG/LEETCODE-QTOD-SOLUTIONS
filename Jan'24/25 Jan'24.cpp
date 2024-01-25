class Solution {
    
// private:
//     int helpme(int i, int j, string text1, string text2, vector<vector<int>>&dp)
//     {

//         if (i < 0 or j < 0)   return 0;
//         if (dp[i][j] != -1)   return dp[i][j];
//         int notTake1 = 0 + helpme(i-1, j, text1, text2, dp);
//         int notTake2 = 0 + helpme(i, j-1, text1, text2, dp);
        
//         int take = 0;
//         if (text1[i] == text2[j])   take = 1 + helpme(i-1, j-1, text1, text2, dp);
        
//         return dp[i][j] =  max(take, max(notTake1, notTake2));
//     }
    
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        //memoization:
        // int n = text1.size();
        // int m = text2.size();
        // vector<vector<int>>dp(n, vector<int>(m,-1));
        // return helpme(n-1, m-1, text1, text2, dp);
        
        
        
        
        //Tabulation:
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        
        for (int i=0;i<=n;i++)   dp[i][0] = 0;
        for (int i=0;i<=m;i++)   dp[0][i] = 0;
        
         for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
             
                int notTake1 = 0 + dp[i-1][j];
                int notTake2 = 0 + dp[i][j-1];

                int take = 0;
                if (text1[i-1] == text2[j-1])   take = 1 + dp[i-1][j-1];
                dp[i][j] =  max(take, max(notTake1, notTake2));
            }
        }
        
        return dp[n][m];
    }
};