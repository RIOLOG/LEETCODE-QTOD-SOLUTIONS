class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        int n = words.size();
        if (n == 1)
            return true;
        unordered_map<char, int> mp;

        for (int i = 0; i < words.size(); i++)
        {
            string temp = words[i];
            for (int j = 0; j < temp.size(); j++)
                mp[temp[j]] += 1;
        }

        for (auto x : mp)
        {
            if (x.second % n != 0)
                return false;
        }

        return true;
    }
};