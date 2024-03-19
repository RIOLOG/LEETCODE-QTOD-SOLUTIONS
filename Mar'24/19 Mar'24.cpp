class Solution
{
public:
    int leastInterval(vector<char> &nums, int n)
    {
        priority_queue<int> pq;
        unordered_map<char, int> mp;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]] += 1;

        for (auto x : mp)
            pq.push(x.second);

        while (!pq.empty())
        {
            int repeat = n + 1;
            vector<int> temp;

            while (repeat > 0 and !pq.empty())
            {
                int top = pq.top();
                pq.pop();
                top -= 1;
                count += 1;
                repeat -= 1;

                if (top > 0)
                    temp.push_back(top);
            }

            for (int i = 0; i < temp.size(); i++)
            {
                pq.push(temp[i]);
            }

            if (pq.empty())
                break;

            if (repeat > 0)
                count += repeat;
        }

        return count;
    }
};