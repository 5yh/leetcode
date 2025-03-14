class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> pairs{
            {']', '['},
            {')', '('},
            {'}', '{'}};
        stack<char> stk;
        for (char ch : s)
        {
            if (pairs.count(ch))
            {
                if (stk.empty() || pairs[ch] != stk.top())
                {
                    return false;
                }
                stk.pop();
            }
            else
            {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};