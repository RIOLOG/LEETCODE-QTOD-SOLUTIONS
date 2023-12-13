class Solution {
private:
    bool helpme(int row, int col, vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for (int i=0;i<m;i++)
        {
            if (i != col and matrix[row][i] == 1)   return false;
        }
        for (int j=0;j<n;j++)
        {
            if (j != row and matrix[j][col] == 1)   return false;
        }
        
        return true;
    }
                
public:
    int numSpecial(vector<vector<int>>& mat) 
    {
        int count = 0;
        for(int i=0;i<mat.size();i++)
        {
            for (int j=0;j<mat[0].size();j++)
            {
                if (mat[i][j] == 1)
                {
                    // cout<<"i"<<" "<<i<<" "<<"j"<<" "<<j<<endl;
                    if (helpme(i,j,mat))   count += 1;
                }
            }
        }
        return count;
    }
};