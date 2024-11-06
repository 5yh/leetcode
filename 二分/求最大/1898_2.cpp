class Solution
{
public:
    bool iszixulie(string &a, string &b, vector<int> &removable, int mid)
    {
        int p1 = 0, p2 = 0;
        int m = a.size();
        int n = b.size();
        // vector比unorderedset快很多
        vector<int> aaa(m, 0);
        for (int i = 0; i < mid; i++)
        {
            aaa[removable[i]] = 1;
        }
        // b是不是a的子序列

        while (aaa[p1] == 1 && a[p1] != b[p2] && p1 < m && p2 < n)
        {
            p1++;
        }
        while (p1 < m && p2 < n)
        {
            if (aaa[p1] != 1 && a[p1] == b[p2])
            {
                p2++;
            }
            p1++;
        }
        if (p2 == n)
        {
            return true;
        }
        return false;
    }
    int maximumRemovals(string s, string p, vector<int> &removable)
    {
        int n = removable.size();
        int l = -1;
        int r = n + 1;
        while (l + 1 < r)
        {
            int m = (r - l) / 2 + l;
            if (iszixulie(s, p, removable, m))
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        return l;
    }
};