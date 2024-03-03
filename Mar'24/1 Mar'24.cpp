class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {

        int l = s.length(), count = 0;

        for (int i = 0; i < l; ++i)
        {
            if (s[i] == '1')
                ++count;
        }

        string str = "";

        for (int i = 0; i < count - 1; ++i)
            str += '1';

        for (int i = 0; i < l - count; ++i)
            str += '0';

        str += '1';

        return str;
    }
};