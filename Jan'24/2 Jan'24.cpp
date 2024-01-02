class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        vector<int> temp;
        int n = nums.size();
        vector<bool> vis(n, false);

        // for (int i=0;i<vis.size();i++)   cout<<vis[i]<<" ";
        // cout<<endl;

        for (int i = 0; i < nums.size(); i++)
        {
            if (!vis[i])
            {
                // vis[i] = true;
                for (int j = 0; j < nums.size(); j++)
                {
                    if (!vis[j] and !mp[nums[j]])
                    {
                        temp.push_back(nums[j]);
                        vis[j] = true;
                        mp[nums[j]] += 1;
                    }
                }
                ans.push_back(temp);
                temp.clear();
                mp.clear();
            }
        }

        if (temp.size() > 0)
            ans.push_back(temp);
        return ans;
    }
};