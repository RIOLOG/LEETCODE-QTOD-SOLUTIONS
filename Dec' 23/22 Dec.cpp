class Solution
{
public:
    int maxScore(string s)
    {
        int n = s.size();
        int one = 0, zero = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
                one += 1;

        int maxi = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '0')
                zero += 1;
            else
                one -= 1;
            maxi = max(maxi, zero + one);
        }

        return maxi;
    }
};