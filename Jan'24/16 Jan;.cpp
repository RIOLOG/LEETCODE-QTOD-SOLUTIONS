
class RandomizedSet {
public:
    map<int,int>mp;
    RandomizedSet() 
    {
        
    }
    
    bool insert(int val) 
    {
        if (mp.find(val) != mp.end())   return false;
        else
        {
            mp[val] += 1;
            return true;
        }
        
    }
    
    bool remove(int val) 
    {
        if (mp.find(val) != mp.end())
        {
            mp.erase(val);
            return true;
        }
        else   return false;
        
    }
    
    int getRandom()
    {
        vector<int>temp;
        for(auto x: mp)   temp.push_back(x.first);
        
        int ind = rand() % temp.size();
        return temp[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */