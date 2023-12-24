class Solution
{
public:
    int minOperations(string s)
    {
        string s1 = "1";
        string s2 = "0";
        int n = s.size();

        for (int i = 1; i < n; i++)
        {
            if (s1[i - 1] == '1')
                s1 += '0';
            else
                s1 += '1';
        }
        for (int i = 1; i < n; i++)
        {
            if (s2[i - 1] == '1')
                s2 += '0';
            else
                s2 += '1';
        }

        // cout<<"s1"<<" "<<s1<<endl;
        // cout<<"s2"<<" "<<s2<<endl;

        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s[i])
                count1 += 1;
            if (s2[i] != s[i])
                count2 += 1;
        }

        return min(count1, count2);
    }
};