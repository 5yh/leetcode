class Solution
{
public:
    bool manzu(vector<int> &inventory, int orders, int mi)
    {
        int cnt = 0;
        for (int i = 0; i < inventory.size(); i++)
        {
            cnt += max(inventory[i] - mi, 0);
            if (cnt >= orders)
            {
                return true;
            }
        }
        return false;
    }
    int maxProfit(vector<int> &inventory, int orders)
    {
        // 贪心，但不用堆，直接排序后分析
        // 二分最后一次卖出时球的价格
        int l = 0;
        int r = 1e9;
        while (l + 1 < r)
        {
            int m = (r - l) / 2 + l;
            if (manzu(inventory, orders, m))
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        // cout << r;
        long ans = 0;
        long mod = 1e9 + 7;
        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i] > r)
            {
                ans += ((long)(inventory[i] + r + 1) * (long)(inventory[i] - r)) / 2;
                ans %= mod;
                orders -= inventory[i] - r;
            }
        }
        // cout << orders;
        ans += (long)r * (long)orders;
        ans %= mod;
        return ans;

        // long res = 0, mod = 1e9 + 7;
        // for (int i : inventory)
        // {
        //     if (i > r)
        //     {
        //         res += ((long)(i + r + 1) * (long)(i - r)) >> 1;
        //         res %= mod;
        //         orders -= i - r;
        //     }
        // }
        // cout << orders;
        // res += (long)r * (long)orders;
        // res %= mod;
        // return res;
    }
};