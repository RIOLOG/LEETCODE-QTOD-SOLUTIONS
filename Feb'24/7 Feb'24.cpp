class Solution {
public:
    string frequencySort(string s) 
    {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;
        
        for (int i=0;i<s.size();i++)   mp[s[i]] ++;
        
        //putting in pq:
        for (auto x:mp)
        {
            pq.push({x.second, x.first});
        }
        
        string ans = "";
        
        while(!pq.empty())
        {
            char top = pq.top().second;
            int times = pq.top().first;
            pq.pop();
            
            for (int i=0;i<times;i++)
            {
                ans += top;
            }
        }
        
        return ans;
    }
};