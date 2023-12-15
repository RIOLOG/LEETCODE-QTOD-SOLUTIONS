class Solution {
public:
    string destCity(vector<vector<string>>& path) 
    {
        map<string,string>mp;
        for (int i=0;i<path.size();i++)
        {
            vector<string>temp = path[i];
            mp[temp[0]] = temp[1];
        }
        
        // for(auto x: mp)
        // {
        //     cout<<x.first<<":"<<x.second<<endl;
        // }
        
        for (auto x:mp)
        {
            string place = x.second;
            if (mp.find(place) == mp.end())   return place;
        }
        
        return "";
    }
};