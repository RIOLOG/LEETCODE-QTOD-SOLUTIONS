class Solution {
private:
    int helpme(int ind, vector<int>&nums, int d, vector<vector<int>>&dp)
    {
        if (ind == nums.size() and d == 0)   return 0;
        if (ind >= nums.size() or d == 0)    return 1e8;
        
        if (dp[ind][d] != -1)   return dp[ind][d];
        
        int ans = 1e8;
        int maxi = -1e8;
        
        for (int j=ind;j<nums.size();j++)
        {
            maxi = max(maxi, nums[j]);
            int cals = helpme(j+1, nums, d-1, dp);
            if (cals != 1e8)   ans = min(ans , maxi + cals);
        }
        
        return dp[ind][d] = ans;
    }
    
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        //memoization:
        int n  = jobDifficulty.size();
        if (jobDifficulty.size() < d)   return -1;
        
        vector<vector<int>>dp(n+1, vector<int>(d+1, -1));
        return helpme(0, jobDifficulty, d, dp);

    }
};