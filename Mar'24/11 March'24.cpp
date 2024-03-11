class Solution {
public:
    string customSortString(string order, string s) 
    {
        //using hashMap;
        map<char, int>mp;
        for (int i=0;i<s.size();i++)   mp[s[i]] ++;
        
        string ans = "";
        for (int i=0;i<order.size();i++)
        {
            if (mp.find(order[i]) != mp.end())
            {
                // ans += order[i];
                // mp[order[i]] -= 1;
                int freq = mp[order[i]];
                cout<<freq<<" "<<order[i]<<endl;
                
                while(freq)
                {
                    ans += order[i];
                    freq -= 1;
                }
                mp.erase(order[i]);
            }
        }
        
        
        for (auto x:mp)  
        {
            int freq = x.second;
            //cout<<freq<<" "<<order[i]<<endl;

            while(freq)
            {
                ans += x.first;
                freq -= 1;
            }
        }
        
        return ans;
    }
};