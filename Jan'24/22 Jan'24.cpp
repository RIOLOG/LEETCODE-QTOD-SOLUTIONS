class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int twice = 0;
        for (int i=0;i<nums.size()-1;i++)
        {
            if (nums[i] == nums[i+1])
            {
                twice = nums[i];
                break;
            }
        }
        
        int missing = 1;
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i] != missing and nums[i] == twice)   continue;
            else if (nums[i] != missing and nums[i] != twice)   break;
            missing += 1;
        }
        
        return {twice, missing};
    }
};