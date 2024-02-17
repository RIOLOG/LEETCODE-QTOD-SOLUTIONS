class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>>mp;
        for (int i=0;i<strs.size();i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }
        
        // for (auto x:mp)
        // {
        //     cout<<x.first<<":";
        //     for (auto y:x.second)
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        
        vector<vector<string>>ans;
        for (auto x:mp)
        {
            vector<string>temp = x.second;
            //for (auto y:x.second)   temp.push_back(y);
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};