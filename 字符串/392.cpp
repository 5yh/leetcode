class Solution
{
public:
    // 子序列
    bool isSubsequence(string t, string s)
    {
        int p1 = 0;
        int p2 = 0;
        while (s[p1] != t[p2] && p1 < s.size() && p2 < t.size())
        {
            p1++;
        }

        while (p1 < s.size() && p2 < t.size())
        {
            // cout << "p1 " << p1 << "p2 " << p2 << ' ' << s[p1] << ' ' << t[p2] << endl;
            if (s[p1] == t[p2])
            {
                p2++;
            }
            p1++;
        }
        if (p2 == t.size())
        {
            return true;
        }
        return false;
    }
};