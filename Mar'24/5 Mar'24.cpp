class Solution {
public:
    int minimumLength(string s) 
    {
        int n = s.size();
        int i = 0, j = n-1;
        int count = 0;
        
        while(i  < j)
        {
            if (s[i] == s[j])
            {
                while(j > i and s[j] == s[j-1])     j -= 1;
                while(i < j and s[i+1] == s[i])     i += 1;
                i += 1;
                j -= 1;
            }
            else    break;
        }
        
        if (i > j)    return 0;
        return(j-i+1);
    }
};