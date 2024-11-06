class Solution
{
public:
    bool manzu(int n, vector<int> &quantities, int m, int mid)
    {
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            cnt += (quantities[i] - 1) / mid + 1;
        }
        if (cnt <= n)
        {
            return true;
        }
        return false;
    }
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int m = quantities.size();
        int l = 0;
        int r = 100000;
        while (l + 1 < r)
        {
            int mid = (r - l) / 2 + l;
            if (manzu(n, quantities, m, mid))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return r;
    }
};