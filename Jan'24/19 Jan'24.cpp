class Solution {
public: 
//     int rec(int i, int j,vector<vector<int>>& matrix,vector<vector<int>>&dp)
//     {
//         if (j < 0 || j >= matrix[0].size()) return 1e8;
//         if (i == 0)  return matrix[i][j];
        
//         if (dp[i][j] != -1)   return dp[i][j];
        
//         int st = matrix[i][j] + rec(i-1,j,matrix,dp);
//         int left = matrix[i][j] + rec(i-1,j-1,matrix,dp);
//         int right = matrix[i][j] + rec(i-1,j+1,matrix,dp);
//         return dp[i][j] =  min(st,min(right,left));
//     }
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        //RECURSION:
        // int n = matrix.size();
        // int m = matrix[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // int maxi = 1e8;
        // for (int j=0;j<m;j++)
        // {
        //     maxi = min(maxi,rec(n-1,j,matrix,dp));
        // }
        // return maxi;
        
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e8));

        for (int j = 0; j < m; j++) 
        {
            dp[0][j] = matrix[0][j];
        }


        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < m; ++j) 
            {
                int left = (j > 0) ? dp[i - 1][j - 1] : 1e8;
                int up = dp[i - 1][j];
                int right = (j < m - 1) ? dp[i - 1][j + 1] : 1e8;

       
                dp[i][j] = matrix[i][j] + min(left, min(up, right));
            }
        }

        int result = 1e8;
        for (int j = 0; j < m; ++j) 
        {
            result = min(result, dp[n - 1][j]);
        }

        return result;
    }
};