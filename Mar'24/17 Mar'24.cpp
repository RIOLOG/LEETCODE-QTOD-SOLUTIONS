class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &nums, vector<int> &arr)
    {
        nums.push_back(arr);

        // MERGE INTERVAL:
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int ind = 1;
        int start = nums[0][0];
        int end = nums[0][1];

        while (ind < nums.size())
        {
            if (end >= nums[ind][0])
                end = max(end, nums[ind][1]);
            else
            {
                ans.push_back({start, end});
                start = nums[ind][0];
                end = nums[ind][1];
            }
            ind += 1;
        }
        ans.push_back({start, end});

        return ans;
    }
};