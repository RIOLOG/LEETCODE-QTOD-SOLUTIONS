class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.size() != word2.size())
            return false;
        unordered_map<char, int> mp2;
        for (int i = 0; i < word2.size(); i++)
            mp2[word2[i]]++;

        for (int i = 0; i < word1.size(); i++)
        {
            char x = word1[i];
            if (mp2.find(x) == mp2.end())
                return false;
        }

        vector<int> v2;
        for (auto x : mp2)
            v2.push_back(x.second);

        mp2.clear();
        vector<int> v1;
        for (int i = 0; i < word1.size(); i++)
            mp2[word1[i]]++;
        for (auto x : mp2)
            v1.push_back(x.second);

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return (v1 == v2);
    }
};