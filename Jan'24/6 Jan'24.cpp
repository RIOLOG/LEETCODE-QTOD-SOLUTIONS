class Solution
{
    // private:
    //     int helpme(int st, int ed, vector<pair<pair<int,int>,int>>&nums, int ind, vector<vector<vector<int>>>&dp)
    //     {
    //         if (ind >= nums.size())   return 0;
    //         if (dp[ind][st][ed] != -1)   return dp[ind][st][ed];
    //         int notTake = 0 + helpme(st, ed, nums, ind+1, dp);

    //         int take = 0;
    //         if(ed <= nums[ind].first.first)
    //         {
    //             int start = nums[ind].first.first;
    //             int end = nums[ind].first.second;
    //             take = nums[ind].second + helpme(start, end, nums, ind+1, dp);
    //         }

    //         return dp[ind][st][ed] = max(take, notTake);
    //     }

    int solve(int s, int end, vector<int> &dp, vector<vector<int>> &nums)
    {
        if (s >= nums.size())
            return 0;

        while (s < nums.size() && nums[s][0] < end)
            s += 1;

        if (dp[s] != -1)
            return dp[s];

        int notTake = 0;
        int take = 0;
        if (nums[s][0] >= end)
        {
            notTake = solve(s + 1, end, dp, nums);
            take = nums[s][2] + solve(s + 1, nums[s][1], dp, nums);
        }
        return dp[s] = max(notTake, take);
    }

public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        // MEMORY LIMIT EXCEEDS:
        //         vector<pair<pair<int,int>,int>>nums;
        //         int ind = 0;
        //         while(ind < startTime.size())
        //         {
        //             nums.push_back({{startTime[ind], endTime[ind]}, profit[ind]});
        //             ind += 1;
        //         }

        //         sort(nums.begin(), nums.end());
        //         // for (const auto& elem : nums)
        //         // {
        //         //     std::cout << "(" << elem.first.first << ", " << elem.first.second << ") - " << elem.second << std::endl;
        //         // }

        //         //int st = nums[0].first.first;
        //         //int ed = nums[0].first.second;
        //         // cout<<st<<" "<<ed<<endl;
        //         // return 0;
        //         int stMax = *max_element(startTime.begin(), startTime.end());
        //         int edMax = *max_element(endTime.begin(), endTime.end());

        //         int n = nums.size();
        //         vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(stMax+1, vector<int>(edMax+1, -1)));

        //         return helpme(0, 0, nums, 0, dp);

        // memoization (TLE):
        vector<vector<int>> nums;
        int i, n = endTime.size();
        for (i = 0; i < n; i++)
        {
            nums.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(nums.begin(), nums.end());
        vector<int> dp(n, -1);
        return solve(0, 0, dp, nums);

        // Tabualtion:
        //         vector<vector<int>> nums;
        //         int n = nums.size();
        //         for(int i = 0; i < n; i++)
        //         {
        //             nums.push_back({startTime[i],endTime[i],profit[i]});
        //         }
        //         sort(nums.begin(),nums.end());
        //         vector<int> dp(n+1,0);

        //         //dp[n] = 0;
        //         int end = 0;

        //         for (int i=n-1;i>=0;i--)
        //         {
        //             if(nums[i][0] < end)  dp[i] = dp[i+1];

        //             int notTake = 0;
        //             int take = 0;
        //             if (nums[i][0] >= end)
        //             {
        //                 notTake = dp[i+1];
        //                 take = nums[i][2] + dp[i+1];
        //                 end = nums[i][0];
        //             }
        //             dp[i] = max(notTake, take);

        //         }

        //         return  *max_element(dp.begin(), dp.end());
    }
};