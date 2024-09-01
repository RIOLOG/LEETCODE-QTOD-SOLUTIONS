class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& nums, int m, int n) 
    {
        if (nums.size() != m*n)    return {};
        vector<vector<int>>ans(m, vector<int>(n, 0));
        
        int ind = 0;
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                ans[i][j] = nums[ind];
                ind += 1;
            }
        }
        
        return ans;
    }
};