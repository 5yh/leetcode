class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string pref = "";
        int minlen = INT_MAX;
        for (int i = 0; i < strs.size(); i++)
        {
            minlen = minlen < strs[i].size() ? minlen : strs[i].size();
        }
        for (int i = 0; i < minlen; i++)
        {
            char nowt = strs[0][i];
            int j = 1;
            for (; j < strs.size(); j++)
            {
                if (nowt != strs[j][i])
                {
                    return pref;
                }
            }
            pref += nowt;
        }
        return pref;
    }
};