class Solution
{
private:
    //     bool compare(vector<int>&first, vector<int>&second)
    //     {
    //         if (first[0] == second[0])   return first[1]  > second[1];
    //         return first[0] < second[0];
    //     }

    struct compare
    {
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            return a.second > b.second;
        }
    };

public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        vector<vector<pair<int, int>>> graph(n);

        for (auto x : meetings)
        {
            int u = x[0];
            int v = x[1];
            int time = x[2];

            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }

        vector<bool> visited(n, false);
        // visited[0] = true;

        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

        pq.push({0, 0});
        pq.push({firstPerson, 0});

        while (!pq.empty())
        {
            auto x = pq.top();
            pq.pop();

            int node = x.first;
            int time = x.second;

            if (visited[node])
                continue;
            visited[node] = true;

            for (auto y : graph[node])
            {
                int nodeParent = y.first;
                int nodeTime = y.second;

                if (!visited[nodeParent] and nodeTime >= time)
                {
                    pq.push({nodeParent, nodeTime});
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == true)
                ans.push_back(i);
        }

        return ans;
    }
};