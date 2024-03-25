class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {

        vector<int> ans;

        unordered_map<int, int> mnums;
        for (int i = 0; i < nums.size(); i++)
            mnums[nums[i]]++;

        for (auto &c : mnums)
            if (c.second == 2)
                ans.push_back(c.first);

        return ans;
    }