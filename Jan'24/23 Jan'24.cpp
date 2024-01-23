class Solution {
private:
    bool canTake(string temp, string res)
    {
        unordered_map<char, int>mp;
        for (auto x:temp)   mp[x]++;
        for (int i=0;i<res.size();i++)
        {
            if (mp.find(res[i]) != mp.end())   return false;
        }
        return true;
    }
    
    int helpme(int prev, int ind, vector<string>& arr, string rio)
    {
        if (ind >= arr.size())   return 0;
        
        int notTake = 0 , take = 0;
        
        //notTake:
        notTake = 0 + helpme(prev, ind+1, arr, rio);
        
        //take:
        if (prev == -1 or canTake(arr[ind], rio))
        {
            string taking = arr[ind];
            take = taking.size() + helpme(ind, ind+1, arr, rio + arr[ind]);
        }
        
        return max(take, notTake);
    }
    
public:
    int maxLength(vector<string>& arr) 
    {
        vector<string>temp;
        unordered_map<char, int>st;
        
        for (int i=0;i<arr.size();i++)
        {
            bool ispresent = false;
            string todo = arr[i];
            
            for (int j=0;j<todo.size();j++)
            {
                if (st.find(todo[j]) != st.end())   ispresent = true;
                st[todo[j]] ++;
            }
            st.clear();
            
            if (ispresent == false)   temp.push_back(todo);
        }
        
        return helpme(-1, 0, temp, "");
    }
};