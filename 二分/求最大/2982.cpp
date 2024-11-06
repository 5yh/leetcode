class Solution
{
public:
    int maximumLength(string s)
    {
        vector<int> groups[26];
        int cnt = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            cnt++;
            // 是最后一个或和下一个不一样
            if (i + 1 == n || s[i] != s[i + 1])
            {
                groups[s[i] - 'a'].push_back(cnt);
                cnt = 0;
            }
        }
        int ans = 0;
        for (auto &a : groups)
        {
            if (a.empty())
                continue;
            ranges::sort(a, greater());
            a.push_back(0);
            a.push_back(0);
            ans = max({ans, a[0] - 2, min(a[0] - 1, a[1]), a[2]});
        }
        return ans ? ans : -1;
    }
};