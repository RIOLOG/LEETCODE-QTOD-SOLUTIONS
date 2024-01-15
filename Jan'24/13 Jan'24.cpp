class Solution {
public:
    int minSteps(string s, string t) 
    {
        //hashmap:
        int count = 0;
        unordered_map<char, int>mp;
        for(int i=0;i<s.size();i++)   mp[s[i]] ++;
        
        unordered_map<char, int>mp1;
        for(int i=0;i<t.size();i++)    mp1[t[i]] ++;
        
        for (int i=0;i<s.size();i++)
        {
            if (mp[s[i]] > mp1[s[i]])
            {
                count += (mp[s[i]] - mp1[s[i]]);
                mp[s[i]] = 0;
            }
        }
        
        return count;
    }
};