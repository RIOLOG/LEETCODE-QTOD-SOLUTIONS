class Solution {
public:
    bool isCircularSentence(string sec) 
    {        
        string temp = "";
        vector<string>s;
        for (int i=0;i<sec.size();i++)
        {
            if (sec[i] == ' ')
            {
                s.push_back(temp);
                temp = "";
            }
            else  temp += sec[i];
        }
        s.push_back(temp);
        
        int n = s.size();
        //cout<<"n "<<n<<endl;
        
        if (n == 1)   
        {
            string temp = s[0];
            return (temp[0] == temp[temp.size() -1]);
        }
        
        string first = "" , last = "";
        bool firstPick = false;
        
        for (int i=0;i<n-1;i++)
        {
            //cout<<s[i]<<" "<<s[i+1]<<endl;
            string curr = s[i];
            string toBe = s[i+1];
            
            int currLen = curr.size();
            int toBeLen = toBe.size();
            
            if (curr[currLen -1] != toBe[0])   return false;
            
            if (firstPick == false)
            {
                firstPick = true;
                first = curr[0];
            }
            last = toBe[toBeLen -1];
        }
        
        return (first == last);
    }
};
