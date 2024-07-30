class Solution
{
public:
    int longestSemiRepetitiveSubstring(string s)
    {
        int n = s.size();
        int l = 0;
        int midpos = 0;
        int ans = 0;
        bool haverepe = false;
        for (int r = 0; r < n; r++)
        {
            if (r != 0)
            {
                if (s[r] == s[r - 1])
                {
                    if (!haverepe)
                    {
                        midpos = r - 1;
                    }
                    else
                    {
                        l = midpos + 1;
                        midpos = r - 1;
                    }
                    haverepe = true;
                }
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};