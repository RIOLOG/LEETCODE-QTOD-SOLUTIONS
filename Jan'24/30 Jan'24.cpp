class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        int ans = 0;
        stack<long long>st;
        for (int i=0;i<tokens.size();i++)
        {
            if (tokens[i] == "+")
            {
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.pop();
                st.push(top2 + top1);
            }
            else if (tokens[i] == "-")
            {
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.pop();
                st.push(top2 - top1);
            }
            else if (tokens[i] == "*")
            {
                long long top1 = st.top();
                st.pop();
                long long top2 = st.top();
                st.pop();
                long long cal = top2*top1;
                st.push(cal);
            }
            else if (tokens[i] == "/")
            {
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.pop();
                st.push(top2/top1);
            }
            else
            {
                long long var = stoi(tokens[i]);
                {
                    st.push(var);
                }
            }
        }
        return st.top();
    }
};