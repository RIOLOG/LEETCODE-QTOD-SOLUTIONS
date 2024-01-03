class Solution
{
private:
    bool helpmeDevice(string temp)
    {
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] == '1')
                return true;
        }
        return false;
    }

    int helpmeCount(string s1, string s2)
    {
        int res = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            for (int j = 0; j < s2.size(); j++)
            {
                if (s1[i] == '1' and s2[j] == '1')
                    res += 1;
            }
        }
        return res;
    }

public:
    int numberOfBeams(vector<string> &bank)
    {
        int count = 0, ans = 0, total = 0;
        vector<string> devices;

        for (int i = 0; i < bank.size(); i++)
        {
            if (helpmeDevice(bank[i]))
                devices.push_back(bank[i]);
        }

        if (devices.size() <= 1)
            return 0;

        for (int i = 0; i < devices.size(); i++)
        {
            string s1 = devices[i];
            for (int j = 0; j < s1.size(); j++)
            {
                if (s1[j] == '1')
                    count += 1;
            }
            if (count != 0)
            {
                ans += (total * count);
                total = count;
                count = 0;
            }
        }

        return ans;

        //         for (int i=0;i<devices.size()-1;i++)
        //         {
        //             string s1 = devices[i];
        //             string s2 = devices[i+1];

        //             int total = helpmeCount (s1, s2);
        //             count += total;
        //         }

        //         return count;
    }
};