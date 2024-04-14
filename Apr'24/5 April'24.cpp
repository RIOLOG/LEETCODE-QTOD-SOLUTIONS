class Solution {
public:
    string makeGood(string s) 
    {
        stack<char> st;
        string ans = "";
        for(int i = 0; i<s.size(); i++)
        {
            if(st.empty())
            {
              st.push(s[i]);
            }
            else
            {
              char top = st.top();
              if(tolower(top) != tolower(s[i]))
              {
                st.push(s[i]);
              }
              else if(islower(top) && isupper(s[i]))
              {
                st.pop();
     a         }
              else if(islower(s[i]) && isupper(top))
              {
                st.pop();
              }
              else
              {
                st.push(s[i]);
              }
            }
        }

        while(!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};