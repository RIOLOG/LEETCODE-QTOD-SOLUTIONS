class Solution {
int mod = 1e9 + 7;
private:
    long long helpme(int row, int col, int move, int startRow, int startCol, vector<vector<vector<long long>>>&dp)
    {
        if (startRow < 0 or startCol < 0 or startRow >= row or startCol >= col)   return 1;
        if (dp[startRow][startCol][move] != -1)   return dp[startRow][startCol][move];
        if (move == 0)   return 0;
        
        long long d1 = 0 , d2 = 0 , d3 = 0 , d4 = 0;
        
        d1 += helpme(row, col, move-1, startRow, startCol+1, dp) % mod;
        d2 += helpme(row, col, move-1, startRow+1, startCol, dp) % mod;
        d3 += helpme(row, col, move-1, startRow, startCol-1, dp) % mod;
        d4 += helpme(row, col, move-1, startRow-1, startCol, dp) % mod;
        
        return dp[startRow][startCol][move] = (d1 + d2 + d3 + d4) % mod;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        vector<vector<vector<long long>>>dp(m+1 ,vector<vector<long long>>(n+1, vector<long long>(maxMove+1, -1)));
        return helpme(m,n,maxMove,startRow,startColumn, dp) % mod;
    }
};