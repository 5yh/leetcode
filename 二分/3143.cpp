class Solution
{
public:
    // 用位运算会快很多
    // 快的有限
    int ans = 0;
    bool manzu(vector<vector<int>> &points, string &s, int m)
    {
        // m是正方形大小
        vector<int> cha(26);
        int n = points.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (abs(points[i][0]) <= m)
            {
                if (abs(points[i][1]) <= m)
                {
                    if (!cha[s[i] - 'a'])
                    {
                        cha[s[i] - 'a']++;
                        cnt++;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        ans = cnt;
        return true;
    }
    int maxPointsInsideSquare(vector<vector<int>> &points, string s)
    {
        int n = points.size();
        int l = -1;
        int r = 1'000'000'001;
        while (l + 1 < r)
        {
            int m = (r - l) / 2 + l;
            if (manzu(points, s, m))
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        return ans;
    }
};