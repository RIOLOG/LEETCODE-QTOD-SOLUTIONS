class Solution {
private:
    bool helpme(int row, int col, vector<vector<bool>>&vis, vector<vector<char>>& board, string word, int len)
    {
        int n = board.size(), m = board[0].size();
        vis[row][col] = true;
        if (len == word.size())   return true;
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        for (int i=0;i<4;i++)
        {
            int nrow = dx[i] + row;
            int ncol = dy[i] + col;
            
  if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == word[len] && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = true;
                if (helpme(nrow, ncol, vis, board, word, len + 1))   return true;

                // Backtracking
                vis[nrow][ncol] = false;
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int n = board.size();
        int m = board[0].size();
        
        for (int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (board[i][j] == word[0])
                {
                    vector<vector<bool>>vis(n, vector<bool>(m, false));
                    //vis[i][j] = true;
                    bool ans = helpme(i, j, vis, board, word, 1);
                    if (ans == true)   return true;
                }
            }
        }
        
        return false;
    }
};