class Solution
{
public:
    bool manzu(string &s, int x)
    {
        int n = s.size();
        int cnt[26]{};
        for (int i = 0; i < n;)
        {
            int j = i + 1;
            while (j < n && s[j] == s[i])
            {
                j++;
            }
            // j指向了第一个不等于s[i]的或数组外
            int k = s[i] - 'a';
            cnt[k] += max(0, j - i - x + 1);
            if (cnt[k] >= 3)
            {
                return true;
            }
            i = j;
        }
        return false;
    }
    int maximumLength(string s)
    {
        int n = s.size();
        int l = -1, r = n + 1;
        while (l + 1 < r)
        {
            int m = (r - l) / 2 + l;
            if (manzu(s, m))
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        return l ? l : -1;
    }
};