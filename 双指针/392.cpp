class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s == "")
            return true;
        for (int i = 0; i < t.size(); i++)
        {
            int j = 0;
            int k = i;
            while (j < s.size())
            {
                if (k >= t.size())
                {
                    break;
                }
                if (s[j] == t[k])
                {
                    j++;
                    k++;
                }
                else
                {
                    k++;
                }
            }
            if (j == s.size())
            {
                return true;
            }
        }
        return false;
    }
};