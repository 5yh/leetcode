class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        // 其实应该对论文篇数二分
        int n = citations.size();
        int l = 0;
        int r = n + 1;
        int ans = 0;
        while (l + 1 < r)
        {
            int m = (r - l) / 2 + l;
            if (citations[n - m] >= m)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        // 注意
        return l;
    }
};