class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n % 3 != 0)
            return {};

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 3)
        {
            vector<int> temp;
            int a = nums[i];
            int b = nums[i + 1];
            int c = nums[i + 2];
            if (abs(a - c) > k)
                return {};
            else
            {
                temp.push_back(a);
                temp.push_back(b);
                temp.push_back(c);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};