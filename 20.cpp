class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (st.empty() || st.top() != '(')
                {
                    return false;
                }
                st.pop();
            }
            else if (s[i] == ']')
            {
                if (st.empty() || st.top() != '[')
                {
                    return false;
                }
                st.pop();
            }
            else if (s[i] == '}')
            {
                if (st.empty() || st.top() != '{')
                {
                    return false;
                }
                st.pop();
            }
        }
        if (st.size() != 0)
            return false;
        return true;
    }
};