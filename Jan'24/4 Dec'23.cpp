class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        unordered_map<int,int>mp;
        int count = 0;
        
        for (int i=0;i<nums.size();i++)   mp[nums[i]]++;
        
        for (auto x: mp)
        {
            if (x.second == 1)   return -1;
            else if (x.second % 3 == 0)   count += x.second / 3;
            else   count += (x.second/3) + 1;
        }
        
        return count;
    }
};