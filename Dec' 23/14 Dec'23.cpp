class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
    {
        int n = grid.size() , m = grid[0].size();

        vector<int>row_one;
        vector<int>col_one;
        
        for (int i=0;i<n;i++)
        {
            int count_one = 0;
            for (int j=0;j<m;j++)
            {
                if (grid[i][j] == 1)   count_one += 1;
            }
            row_one.push_back(count_one);
        }
        
        for (int i=0;i<m;i++)
        {
            int count_one = 0;
            for (int j=0;j<n;j++)
            {
                if (grid[j][i] == 1)   count_one += 1;
            }
            col_one.push_back(count_one);
        }
        
        vector<vector<int>>ans(n,vector<int>(m,0));
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {   
                int cal = row_one[i] + col_one[j] - (n - row_one[i]) - (m - col_one[j]);
                ans[i][j] = cal;
            }
        }
        
        return ans;
    }
};