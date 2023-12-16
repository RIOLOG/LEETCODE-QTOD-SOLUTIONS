class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        // 2 Dec'23
        unordered_map<char, int> mp;
        for (int i = 0; i < chars.size(); i++)
            mp[chars[i]] += 1;

        int ans = 0;
        for (int i = 0; i < words.size(); i++)
        {
            unordered_map<char, int> mp1 = mp;
            string temp = words[i];
            int count = 0;

            for (int j = 0; j < temp.size(); j++)
            {
                if (mp1.find(temp[j]) != mp1.end())
                {
                    count += 1;
                    mp1[temp[j]] -= 1;
                    if (mp1[temp[j]] == 0)
                        mp1.erase(temp[j]);
                }
            }

            if (count == temp.size())
                ans += temp.size();
        }

        return ans;
    }
};