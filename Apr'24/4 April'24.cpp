class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        
        stack<int>st;
        int temp = 0;
        int n = s.size();
        
        for(int i=0;i<n;i++)
        {
           if(s[i] == '(')
           {
               temp++;
               cnt = max(cnt,temp);
           }
            else if(s[i] == ')')
            {
                temp--;
            }
        }
        
        return max(cnt,temp);
        
    }
};