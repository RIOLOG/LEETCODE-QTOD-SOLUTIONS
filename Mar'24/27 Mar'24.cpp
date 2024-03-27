class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;
        int ws = 0;
        int count = 0;
        int p = 1;
        for (int we = 0; we < nums.size(); we++)
        {
            p = p * nums[we];
            while (p >= k)
            {
                p = p / nums[ws];
                ws += 1;
            }
            count = count + (we - ws + 1);
        }
        return count;
    }
};