class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        int n=arr.size();
        unordered_map<int,int>mp;
        unordered_set<int>s;
        
        for (int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        for (auto x:mp)
        {
            s.insert(x.second);
        }
        
        if (s.size()!=mp.size())
        {
            return false;
        }
        return true;
        
    }
};