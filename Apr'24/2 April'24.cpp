class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>mp;
        int n = t.size();
        int m = s.size();
        // cout<<n<<" "<<m<<endl;
        int i = 0 , j = 0;
        
        while(i < s.size() and j < t.size())
        {
            char temp = s[i];
            //cout<<"temp"<<" "<<temp<<endl;
            if (mp.find(temp) == mp.end())
            {
                mp[temp] = t[j];
            }
            
            else
            {
                if (mp[temp] != t[j])    return false;
            }
                
            i += 1;
            j += 1;
        }
        
        // cout<<i<<" "<<j<<endl;
        if (i != m or j != n)    return false;
        
        unordered_map<char, char>mp2;
        for (auto x:mp)
        {
            char key = x.first;
             char val = x.second;
            
            if (mp2.find(val) != mp2.end())
            {
                return false;
            }
            else                              mp2[val] = key;
        }
        
        return true;
        
    }
};