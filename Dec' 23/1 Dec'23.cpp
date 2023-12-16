class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        // 1 Dec'23
        string x = "";
        for (auto it : word1)
        {
            x += it;
        }
        string y = "";
        for (auto it : word2)
        {
            y += it;
        }
        return (x == y);
    }
};