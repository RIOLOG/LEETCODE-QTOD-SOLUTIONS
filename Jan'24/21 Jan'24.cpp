class Solution {
public:
    int rob(vector<int>& nums)
    {
        //tabulation:
//         int n = nums.size();
//         vector<int>dp(n,0);
        
//         if (nums.size() == 1)   return nums[0];
//         if (nums.size() == 2)   return max(nums[0], nums[1]);
        
//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);
//         for (int i=2;i<nums.size();i++)
//         {
//             dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
//         }
        
//         return dp[nums.size()-1];
        
        
        
        //constact space:
        int n = nums.size();
        if (n == 1)   return nums[0];
        if (n == 2)   return max(nums[0], nums[1]);
        
        int first = nums[0];
        int second = max(nums[0], nums[1]);
        
        for (int i=2;i<n;i++)
        {
            int third = max(second, nums[i] + first);
            first = second;
            second = third;
        }
        
        return max(first, second);
    }
};