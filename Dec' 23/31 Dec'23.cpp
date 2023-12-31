class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        // bruteForce:
        int ans = INT_MIN;

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i] == s[j])
                    ans = max(ans, j - i - 1);
            }
        }

        if (ans == INT_MIN)
            return -1;
        return ans;

        // using hashmap:
        int ans = -1;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp.find(s[i]) != mp.end())
            {
                ans = max(ans, i - mp[s[i]] - 1);
            }
            else
                mp[s[i]] = i;
        }

        return ans;
    }
};