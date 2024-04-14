class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        string ans = "";
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                ans += "(";
                st.push('(');
            }
            else if (s[i] == ')')
            {
                if (st.empty())
                    continue;
                else
                {
                    char x = st.top();
                    st.pop();
                    if (x == '(')
                        ans += ")";
                    else
                        continue;
                }
            }
            else
            {
                ans += s[i];
            }
        }

        stack<char> st2;
        int m = ans.size();
        string ansNew = "";

        for (int i = m - 1; i >= 0; i--)
        {
            if (ans[i] == ')')
            {
                ansNew += ")";
                st2.push(')');
            }
            else if (ans[i] == '(')
            {
                if (st2.empty())
                    continue;
                else
                {
                    char x = st2.top();
                    st2.pop();
                    if (x == ')')
                        ansNew += '(';
                    else
                        continue;
                }
            }
            else
            {
                ansNew += ans[i];
            }
        }

        reverse(ansNew.begin(), ansNew.end());
        return ansNew;
    }
};