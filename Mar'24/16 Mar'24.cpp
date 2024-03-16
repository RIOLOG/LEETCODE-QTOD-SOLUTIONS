class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int count = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                count -= 1;
            if (nums[i] == 1)
                count += 1;
            if (count == 0)
                ans = max(ans, i + 1);

            if (mp.find(count) != mp.end())
            {
                ans = max(ans, i - mp[count]);
            }
            else
                mp[count] = i;
        }

        return ans;
    }
};