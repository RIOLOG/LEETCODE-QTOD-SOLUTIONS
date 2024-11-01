class Solution {
public:
    string makeFancyString(string s) 
    {
        string ans = "";
        ans += s[0];
        int count = 1;
        
        for (int i=1;i<s.size();i++)
        {
            if (s[i] == ans.back())
            {
                if (count == 1)
                {
                    ans += s[i];
                    count += 1;
                }
                else
                {
                    //count = 1;
                    continue;
                }
            }
            else
            {
                ans += s[i];
                count = 1;
            }
        }
        
        return ans;
    }
};