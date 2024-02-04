class Solution
{
public:
    string minWindow(string s, string t)
    {
        // unordered_map<char,int>mp;
        // for (int i=0;i<t.size();i++)
        // {
        //     mp[t[i]] ++;
        // }
        // int ans = INT_MAX;
        // int ws = 0;
        // int we = 0;
        // int m = s.size();
        // while(we < m)
        // {
        //     char c = s[we];
        //     if (mp.find(c) != mp.end())
        //     {
        //         mp[s[we]]--;
        //         if (mp.empty() == true)
        //         {
        //             ans = min(ans,we-ws+1);
        //             ws += 1;
        //             we = ws;
        //             for (int i=0;i<t.size();i++)
        //             {
        //                 mp[t[i]]++;
        //             }
        //         }
        //         else
        //         {
        //             we += 1;
        //         }
        //     }
        //     else
        //     {
        //         we += 1;
        //     }
        // }
        // cout<<ans;
        // return "ANC";

        if (s.size() < t.size())
            return "";

        int n = t.size();
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[t[i]]++;
        }
        int ws = 0;
        int we = 0;
        int count = mp.size();
        int len = INT_MAX;

        int start = 0;
        while (we < s.size())
        {
            mp[s[we]]--;
            if (mp[s[we]] == 0)
                count -= 1;
            if (count == 0)
            {
                while (count == 0)
                {
                    if (len > we - ws + 1)
                    {
                        len = min(len, we - ws + 1);
                        start = ws;
                    }
                    mp[s[ws]]++;
                    if (mp[s[ws]] > 0)
                    {
                        count += 1;
                    }
                    ws += 1;
                }
            }
            we += 1;
        }
        if (len != INT_MAX)
            return s.substr(start, len);
        return "";
    }
};