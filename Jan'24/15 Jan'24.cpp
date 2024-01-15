class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        //using hashMAP:
        unordered_map<int,int>winner;
        unordered_map<int,int>looser;
        
        for (int i=0;i<matches.size();i++)
        {
            winner[matches[i][0]] ++;
            looser[matches[i][1]] ++;
        }
        
        vector<int>win;
        vector<int>lose;
        
        for (auto x: winner)
        {
            int player = x.first;
            if (looser.find(player) == looser.end())   win.push_back(player);
        }
        
        for (auto x: looser)
        {
            if (x.second == 1)    lose.push_back(x.first);
        }
        
        sort(win.begin(), win.end());
        sort(lose.begin(), lose.end());
        
        vector<vector<int>>ans;
        ans.push_back(win);
        ans.push_back(lose);
        
        return ans;
    }
};